#include "everything.h"

int main(int argc, char* argv[]) {
  float phase = 0;

  double nyquist = SAMPLE_RATE / 2.0;
  double cutoff = 0.8 * nyquist;

  for (float note = 127; note > 0; note -= 0.001) {
    float frequency = mtof(note);

    // now we have to do the cutoff inside of the loop
    double sample = 0;
    float tmp = frequency;
    int j = 1;
    while (tmp < cutoff) {
        sample += (sin(j * phase) / j);
        tmp += frequency;
        j++;
    }

    sample /= 2.0;
    mono(sample);

    phase += 2 * pi * frequency / SAMPLE_RATE;
    if (phase > 2 * pi)  //
      phase -= 2 * pi;
  }
}
