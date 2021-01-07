#include <string>

#include "everything.h"  // mono

// adapted from sine.cpp
int main(int argc, char* argv[]) {
  double frequency = 440.0;
  if (argc > 1) {
    frequency = std::stof(argv[1]);
  }

  double duration = 1;
  if (argc > 2) {
    duration = std::stof(argv[2]);
  }

  double nyquist = SAMPLE_RATE / 2.0;
  double cutoff = 0.8 * nyquist;
  int nharms = 0;
  double tmp = frequency;

  // count number of harmonics necessary for band-limited signal
  while (tmp < cutoff) {
    nharms++;
    tmp += frequency;
  }

  double phase = 0;
  for (int i = 0; i < duration * SAMPLE_RATE; ++i) {
    double sample = 0;
    // loop from 1 to n exclusive to make the math a little cleaner
    for (int j = 1; j <= nharms; j++) {
       sample += sin(j * phase);
    }

    sample /= nharms;
    mono(sample);

    phase += 2 * pi * frequency / SAMPLE_RATE;

    // Wrap phase into the range (0, 2𝞹). If we didn't, phase would get large.
    // As valid numbers are not uniformly distributed across the range of
    // floating point numbers, we may get a sort of rounding error.
    //
    if (phase > 2 * pi) {
      phase -= 2 * pi;
    }
  }

  return 0;
}
