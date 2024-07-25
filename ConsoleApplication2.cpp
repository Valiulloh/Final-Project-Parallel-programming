#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

using namespace std;

void heat_equation_serial(vector<double>& u, double alpha, double dt, double dx, int num_steps) {
    int n = u.size();
    vector<double> u_new(n);

    for (int step = 0; step < num_steps; ++step) {
        for (int i = 1; i < n - 1; ++i) {
            u_new[i] = u[i] + alpha * dt / (dx * dx) * (u[i + 1] - 2 * u[i] + u[i - 1]);
        }
        u = u_new;
    }
}

void heat_equation_parallel(vector<double>& u, double alpha, double dt, double dx, int num_steps) {
    int n = u.size();
    vector<double> u_new(n);

    for (int step = 0; step < num_steps; ++step) {
#pragma omp parallel for
        for (int i = 1; i < n - 1; ++i) {
            u_new[i] = u[i] + alpha * dt / (dx * dx) * (u[i + 1] - 2 * u[i] + u[i - 1]);
        }
        u = u_new;
    }
}

int main() {
    int n = 1000; // number of grid points
    double alpha = 0.01; // thermal diffusivity
    double dx = 1.0 / (n - 1); // space step size
    double dt = 0.5 * dx * dx / alpha; // time step size (for stability)
    int num_steps = 10000; // number of time steps

    // Initial condition: delta function in the middle
    vector<double> u_serial(n, 0.0);
    u_serial[n / 2] = 1.0;

    vector<double> u_parallel = u_serial;

    double start_time, end_time;

    // Serial computation
    start_time = omp_get_wtime();
    heat_equation_serial(u_serial, alpha, dt, dx, num_steps);
    end_time = omp_get_wtime();
    cout << "Serial computation time: " << end_time - start_time << " seconds" << endl;

    // Parallel computation
    start_time = omp_get_wtime();
    heat_equation_parallel(u_parallel, alpha, dt, dx, num_steps);
    end_time = omp_get_wtime();
    cout << "Parallel computation time: " << end_time - start_time << " seconds" << endl;

    // Verify results
    double error = 0.0;
    for (int i = 0; i < n; ++i) {
        error += fabs(u_serial[i] - u_parallel[i]);
    }
    cout << "Total error between serial and parallel results: " << error << endl;

    return 0;
}
