#include <iostream>
#include <future>
#include <numeric>
#include <thread>

using namespace std;

enum {
    lhsRows = 3,
    lhsCols = 4,
    rhsTRows = 4,
    rhsTCols = 5
};

double innerProduct(double* const lhs, double* const rhs, int size) {
    return inner_product(lhs, lhs + size, rhs, 0.0);
}

int main() {
    
    double lhs[lhsRows][lhsCols];
    double rhsT[rhsTRows][rhsTCols];

    // Fill the matrices with values
    for (size_t rowIdx = 0; rowIdx < lhsRows; ++rowIdx) 
    {
        for (size_t colIdx = 0; colIdx < lhsCols; ++colIdx)
            lhs[rowIdx][colIdx] = rowIdx + colIdx + 1;
    }

    for (size_t rowIdx = 0; rowIdx < rhsTRows; ++rowIdx) 
    {
        for (size_t colIdx = 0; colIdx < rhsTCols; ++colIdx)
            rhsT[rowIdx][colIdx] = rowIdx + colIdx + 2;
    }

    future<double> fut[lhsRows][rhsTRows]; // Array to hold futures

    // Start tasks in detached threads
    for (size_t rowIdx = 0; rowIdx < lhsRows; ++rowIdx) 
    {
        for (size_t colIdx = 0; colIdx < rhsTRows; ++colIdx) 
        {
            // Create a new packaged_task for each computation
            packaged_task<double(double*, double*, int)> task(innerProduct);
            fut[rowIdx][colIdx] = task.get_future();

            // Detach the thread to execute the task
            thread(std::move(task), lhs[rowIdx], rhsT[colIdx], lhsCols).detach();
        }
    }

    // Retrieve and display the results
    for (size_t rowIdx = 0; rowIdx < lhsRows; ++rowIdx) {
        for (size_t colIdx = 0; colIdx < rhsTRows; ++colIdx) 
            cout << fut[rowIdx][colIdx].get() << " ";
        cout << "\n";
    }
}