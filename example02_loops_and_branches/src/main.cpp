#include "Eligibility.h"
#include "Preparation.h"
#include "Code.h"

int main() {

	// only proceed if age_check returns true
	if (age_check() == false) {

		return -1; // returning with a failure
	}

	if (purpose_check() == false) {

		return -1;
	}

	turn_lights_on();

	start_coding();

	return 0;
}