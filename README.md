Parallel Heat Equation Solver
Project Overview
This project implements a solver for the heat equation using finite difference methods, with both serial and parallel implementations.
The parallel version leverages OpenMP to improve performance through multi-threading. The heat equation is a partial differential equation that describes the distribution of heat in a given region over time.
This project aims to compare the performance of the serial and parallel implementations and verify that both produce identical results.

Key Features:
Serial implementation of the heat equation solver.
Parallel implementation using OpenMP.
Performance comparison between serial and parallel versions.
Verification of correctness by comparing the results of both implementations.

Prerequisites:
Visual Studio (with Desktop development with C++ workload installed)
OpenMP (enabled by default in Visual Studio C++ projects)
Getting Started

Clone the Repository:
If you have a repository for this project, clone it to your local machine. If not, proceed to manually create the project.
Create a New Project in Visual Studio:

Open Visual Studio.
Go to File -> New -> Project.
In the Create a new project dialog, select Console App.
Click Next.
Enter a Project name (e.g., HeatEquationSolver) and choose a Location.
Click Create.
Configure OpenMP Support:

Right-click on your project in the Solution Explorer and select Properties.
In the Property Pages dialog, navigate to Configuration Properties -> C/C++ -> Language.
Set OpenMP Support to Yes.
Click Apply and then OK.
Add the Source Code:

In Solution Explorer, right-click on Source Files and select Add -> New Item.
Select C++ File (.cpp) and name the file main.cpp.
Click Add.
Copy and paste the provided source code into main.cpp.
