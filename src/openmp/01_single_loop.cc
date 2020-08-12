#include <iostream>
#include <omp.h>
#include <chrono>
using namespace std;
typedef std::chrono::milliseconds timestamp;

int main()
{
  double wall_timer;
  double c[10000];
  for (int n_threads = 1; n_threads <= 10; ++n_threads) {
    auto clock_timer = std::chrono::high_resolution_clock::now();
    wall_timer = omp_get_wtime();
    cout << "thread_num = " << n_threads << endl;
    #ifdef _OPENMP
      #pragma omp parallel for collapse(2) num_threads(n_threads)
    #endif
      for (int i = 0; i < 1280; i++) {
        for (int j = 0; j < 720; j++) {
          c[i] = i + j;
        }
      }
    cout << "Time on clock = "
         << (std::chrono::duration_cast<timestamp>(
                std::chrono::high_resolution_clock::now() - clock_timer)).count() / 1000.0
         << endl;
    cout << "Time with wall = " << omp_get_wtime() - wall_timer << endl;
  }
  
  return 0;
}