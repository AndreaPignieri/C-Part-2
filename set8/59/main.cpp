#include "main.ih"

int main(int argc, char **argv)
{
    --argc;
    ++argv;
    int arr[argc];
    for (int idx = 0; idx != argc; ++idx)
        arr[idx] = stoi(string{argv[idx]});

    Qsort(arr, arr + argc);

    for (int idx = 0; idx != argc; ++idx)
        cout << arr[idx] << '\n';
}