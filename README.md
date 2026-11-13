\# MPI Laboratory Work 3



Laboratory project for the Distributed Computing course.



\## Description



A C++ console application demonstrating message exchange between multiple MPI processes.



\## Technologies



\- C++

\- Microsoft Visual Studio

\- MPICH2 (MPI library)



\## Requirements



\- Windows

\- Microsoft Visual Studio with C++ development tools

\- MPICH2 with development libraries and MPI runtime



\## Build and Run



1\. Clone the repository.

2\. Install and configure MPICH2.

3\. Open `lab3.slnx` in Visual Studio.

4\. Check the MPI include and library directories in the project properties.

5\. Build the project.

6\. Run the compiled application using three MPI processes:



&#x20;  `mpiexec -n 3 path/to/lab3.exe`



\## Notes



The Visual Studio project currently uses MPICH2 paths under:



`C:\\Program Files (x86)\\MPICH2`



If MPICH2 is installed elsewhere, update the include and library paths in the Visual Studio project properties.

