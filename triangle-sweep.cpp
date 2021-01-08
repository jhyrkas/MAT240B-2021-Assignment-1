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
        double mult = pow(-1.0, (j-1)/2) / (j*j);
        sample += mult * sin(j * phase);
        tmp += (frequency*2);
        j += 2;
    }

    sample *= (8.0 / (pi*pi));
    mono(sample);

    phase += 2 * pi * frequency / SAMPLE_RATE;
    if (phase > 2 * pi)  //
      phase -= 2 * pi;
  }
}
