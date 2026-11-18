# EduMPI GUI – Frontend 

**EduMPI GUI** is the graphical interface for [EduMPI](https://github.com/AnnaLena77/EduMPI),  
an Open MPI fork with integrated near-real-time performance measurement.  

The GUI provides students and educators with a **simple, intuitive way to run MPI applications on HPC clusters**  
and to **visualize communication patterns, performance metrics, and wait states** without prior knowledge of SSH, SLURM, or traditional profiling tools.

---

## ✨ Key Features

- **Simplified Cluster Access**
  - No SSH or SLURM scripting required  
  - Direct login via GUI  
  - Automatic file upload and job submission  

- **Job Management**
  - Select MPI executable and number of processes  
  - Start, monitor, and abort jobs interactively  
  - View job status in real-time  

- **Integrated Visualization**
  - **2D process view**: communication, bytes sent/received, wait times  
  - **3D cluster view**: processes as colored cubes on their physical nodes  
  - **Communication matrix**: direct process-to-process message analysis  
  - Interactive timeline navigation (per-second or interval-based)  

- **Educational Focus**
  - Helps students understand MPI behavior through visual cues  
  - Removes barriers of complex HPC toolchains  
  - Designed for classroom and lab exercises  

---

## ⚙️ Architecture

The GUI acts as the **frontend client** in the EduMPI ecosystem:

1. Students launch the GUI (AppImage or local build)  
2. Login to the HPC cluster with provided credentials  
3. Select an MPI program and execution parameters  
4. EduMPI (cluster-side) executes the job and writes performance data to **TimescaleDB**  
5. The GUI queries aggregated data in near-real-time and visualizes results  

![GUI Workflow](docs/architecture/pictogram.png)

---

## 🖥️ Screenshots


  ![Screenshot](docs/screenshots/gui.png)

---

## 🚀 Installation

### Option 1: Download Prebuilt AppImage (Recommended)
1. Download the [EduMPI GUI AppImage](https://github.com/AnnaLena77/EduMPI_GUI_Download)  
2. Make it executable:  
   ```bash
   chmod +x EduMPI_GUI-x86_64.AppImage
   ```
3. run it:
   ```bash
    ./EduMPI_GUI-x86_64.AppImage
    ```

### Option 2: Build from Source
1. Clone the repository:
     ```bash
    git clone git@github.com:AnnaLena77/EduMPI_GUI.git
    cd EduMPI_GUI
    ```
2. Install dependencies: Qt 6.12 (Quick3D, ShaderTools, Sql)
3. Build using CMake
4. Run the resulting binary

### Dev mode (local dev cluster)
For development against the local container cluster in the EduMPI repo (`dev/`), configure with
`-DEDUMPI_DEV_MODE=ON` (never used for release builds) and start the GUI from a shell where
`source <EduMPI>/dev/ssh/activate` was run. The GUI then reads the connection values from
`<EduMPI>/dev/gui.env`, connects to the database and the cluster automatically, reconnects every 5 s
after a restart of the dev cluster, and shows "[DEV]" in the window title. Without the flag or without
`EDUMPI_DEV_ENV` the GUI behaves as before. Details: `dev/README.md` in the EduMPI repo.

### Demo mode (tool-edumpi-docker)
The demo repository [tool-edumpi-docker](https://github.com/Sithies/tool-edumpi-docker) ships a
GUI built with `-DEDUMPI_DEMO_MODE=ON -DCMAKE_BUILD_TYPE=Release` together with a containerised
EduMPI cluster. Its start script writes `.run/demo.env` and launches the GUI with `EDUMPI_DEMO_ENV`
pointing to it. The GUI then connects to the database and the cluster automatically (retrying every
5 s), calls `ssh`/`scp` with the demo port, key and `known_hosts` from that file, shows "[DEMO]" in the
title and a status line, limits the rank count to what the demo cluster offers, and hides the
connection dialogs, the SSH key guide and the "Non-Visualization" menu (Score-P and OpenMP are not part
of the demo cluster). Without `EDUMPI_DEMO_ENV` a demo build behaves like the normal GUI.
`EDUMPI_DEV_MODE` and `EDUMPI_DEMO_MODE` cannot be combined.

`appGUI_Cluster --selftest` (used by the demo workflow with `QT_QPA_PLATFORM=offscreen`) checks that
the GUI and the PostgreSQL driver load; in dev or demo mode it also waits for the database and cluster
connection and exits with 0 on success, 1 on failure or 2 if the `QPSQL` driver is missing.

## 📚 References

EduMPI is described in:

- Roth, Anna-Lena; Süß, Tim (2023): *Performance Analysis Tools for MPI Applications and their Use in Programming Education*. In Companion of the 2023 ACM/SPEC International Conference on Performance Engineering (ICPE '23 Companion). Association for Computing Machinery, New York, NY, USA, 361–368. 
DOI: [10.1145/3578245.3584358](https://doi.org/10.1145/3578245.3584358) 
- Roth, Anna-Lena; James, David; Kuhn, Michael; Konert, Johannes (2024): *Enhancing Parallel Programming Education with High-Performance Clusters Utilizing Performance Analysis*. Proceedings of DELFI 2024. DOI: 10.18420/delfi2024_42. Gesellschaft für Informatik e.V. 
DOI: [10.18420/delfi2024_42](https://doi.org/10.18420/delfi2024_42)
- Roth, Anna-Lena; James, David; Kuhn, Michael (2025): *EduMPI – Simplifying the Use of High-Performance Clusters and Focusing Performance Analysis in Parallel Programming Education*. PARS-Mitteilungen: Vol. 37. Gesellschaft für Informatik e.V., Fachgruppe PARS. ISSN: 0177-0454Link: [LINK](https://dl.gi.de/server/api/core/bitstreams/5ee764b8-731a-4b8e-aca4-28cb0538fd7b/content)
- Roth, Anna-Lena; James, David; Kuhn, Michael; Frisch, Dustin (2025): *Making MPI Collective Operations Visible: Understanding Their Utility and Algorithmic insights*. In: Nagel, W.E., Goehringer, D., Diniz, P.C. (eds) Euro-Par 2025: Parallel Processing. Euro-Par 2025. Lecture Notes in Computer Science, vol 15900. Springer, Cham. 
DOI: [10.1007/978-3-031-99854-6_5](https://doi.org/10.1007/978-3-031-99854-6_5)

---

## 🔮 Future Work

- Improve ring buffer adaptivity to avoid overflow in micro-benchmarks  
- Extend support for additional MPI language bindings beyond C  
- Portable integration as an **independent framework** instead of Open MPI fork  
- Additional visualization dashboards (historical runs, anomaly detection)  

---



