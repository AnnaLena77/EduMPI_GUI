#!/bin/bash

# Verzeichnis, in das die Bibliotheken kopiert werden sollen
LIBDIR="./AppDir/usr/lib"

# Liste der zu kopierenden Bibliotheken
INCLUDE_LIBS=(
    "/lib/x86_64-linux-gnu/libgtk-3.so.0"
    "/lib/x86_64-linux-gnu/libgdk-3.so.0"
    "/lib/x86_64-linux-gnu/libgdk_pixbuf-2.0.so.0"
    "/lib/x86_64-linux-gnu/libpangocairo-1.0.so.0"
    "/lib/x86_64-linux-gnu/libpango-1.0.so.0"
    "/lib/x86_64-linux-gnu/libpangoft2-1.0.so.0"
    "/lib/x86_64-linux-gnu/libcairo-gobject.so.2"
    "/lib/x86_64-linux-gnu/libcairo.so.2"
    "/lib/x86_64-linux-gnu/libfribidi.so.0"
    "/lib/x86_64-linux-gnu/libharfbuzz.so.0"
    "/lib/x86_64-linux-gnu/libgraphite2.so.3"
    "/lib/x86_64-linux-gnu/libatk-1.0.so.0"
    "/lib/x86_64-linux-gnu/libatk-bridge-2.0.so.0"
    "/lib/x86_64-linux-gnu/libgio-2.0.so.0"
    "/lib/x86_64-linux-gnu/libepoxy.so.0"
    "/lib/x86_64-linux-gnu/libXi.so.6"
)

# Funktion zum Kopieren von Bibliotheken
copy_lib() {
    local lib=$1
    if [ ! -f "${LIBDIR}/$(basename ${lib})" ]; then
        echo "Kopiere Bibliothek: ${lib}"
        cp ${lib} ${LIBDIR}
    fi
}

# Erstellen des Zielverzeichnisses, falls es nicht existiert
mkdir -p ${LIBDIR}

# Kopieren der notwendigen Bibliotheken
for lib in "${INCLUDE_LIBS[@]}"; do
    copy_lib $lib
done

