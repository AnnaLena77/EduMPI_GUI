#! /bin/bash


set -x

set -e


# building in temporary directory to keep system clean

# use RAM disk if possible (as in: not building on CI system like Travis, and RAM disk is available)

if [ "$CI" == "" ] && [ -d /dev/shm ]; then

    TEMP_BASE=/dev/shm

else

    TEMP_BASE=/tmp

fi


BUILD_DIR=$(mktemp -d -p "$TEMP_BASE" appimage-build-XXXXXX)


# make sure to clean up build dir, even if errors occur

cleanup () {

    if [ -d "$BUILD_DIR" ]; then

        rm -rf "$BUILD_DIR"

    fi

}

trap cleanup EXIT


# store repo root as variable

REPO_ROOT=$(readlink -f $(dirname $(dirname $0)))

OLD_CWD=$(readlink -f .)


# switch to build dir

pushd "$BUILD_DIR"


# configure build files with CMake

# we need to explicitly set the install prefix, as CMake's default is /usr/local for some reason...

cmake "$REPO_ROOT" -DCMAKE_INSTALL_PREFIX=/usr


# build project and install files into AppDir

make -j$(nproc)

make install DESTDIR=AppDir


# now, build AppImage using linuxdeploy and linuxdeploy-plugin-qt

# download linuxdeploy and its Qt plugin

wget https://github.com/linuxdeploy/linuxdeploy/releases/download/continuous/linuxdeploy-x86_64.AppImage

wget https://github.com/linuxdeploy/linuxdeploy-plugin-qt/releases/download/continuous/linuxdeploy-plugin-qt-x86_64.AppImage


# make them executable

chmod +x linuxdeploy*.AppImage


# make sure Qt plugin finds QML sources so it can deploy the imported files

export QML_SOURCES_PATHS="$REPO_ROOT"


# initialize AppDir, bundle shared libraries for QtQuickApp, use Qt plugin to bundle additional resources, and build AppImage, all in one single command

./linuxdeploy-x86_64.AppImage --appdir AppDir --plugin qt --output appimage


# move built AppImage back into original CWD

mv QtQuickApp*.AppImage "$OLD_CWD"
