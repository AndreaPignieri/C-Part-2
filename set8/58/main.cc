#include <iostream>
#include <future>
#include <numeric>
#include <thread>

double innerProduct(double* const lhs, double* const rhs, int size) {
    return std::inner_product(lhs, lhs + size, rhs, 0.0);
}

int main() {
    using namespace std;

    const int lhsRows = 4;
    const int lhsCols = 5;
    const int rhsTRows = 6;
    const int rhsTCols = 5;

    double lhs[lhsRows][lhsCols];
    double rhsT[rhsTRows][rhsTCols];

    // Fill the matrices with values
    for (int rowIdx = 0; rowIdx < lhsRows; ++rowIdx) {
        for (int colIdx = 0; colIdx < lhsCols; ++colIdx) {
            lhs[rowIdx][colIdx] = rowIdx + colIdx + 1;
        }
    }

    for (int rowIdx = 0; rowIdx < rhsTRows; ++rowIdx) {
        for (int colIdx = 0; colIdx < rhsTCols; ++colIdx) {
            rhsT[rowIdx][colIdx] = rowIdx + colIdx + 2;
        }
    }

    future<double> fut[lhsRows][rhsTRows]; // Array to hold futures

    // Start tasks in detached threads
    for (int rowIdx = 0; rowIdx < lhsRows; ++rowIdx) {
        for (int colIdx = 0; colIdx < rhsTRows; ++colIdx) {
            // Create a new packaged_task for each computation
            packaged_task<double(double*, double*, int)> task(innerProduct);
            fut[rowIdx][colIdx] = task.get_future();

            // Detach the thread to execute the task
            thread(std::move(task), lhs[rowIdx], rhsT[colIdx], lhsCols).detach();
        }
    }

    // Retrieve and display the results
    for (int rowIdx = 0; rowIdx < lhsRows; ++rowIdx) {
        for (int colIdx = 0; colIdx < rhsTRows; ++colIdx) {
            cout << fut[rowIdx][colIdx].get() << " ";
        }
        cout << "\n";
    }
}