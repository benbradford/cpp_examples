#include "Eligibility.h"
#include "Preparation.h"
#include "Code.h"

int main() {

	/* if statements are of the form
	
		if (condition) {
			// do something when condition is true
		} else if (another_condition) {
			// do something else when another_condition is true
		} else {
			// do something else when neither of the above conditions are true
		}

		one and only one of the above code blocks will execute
	*/

	if (age_check() == false) { // age_check is in Eligibility.h

		// we enter here only when age_check() returns false
		return -1; // returning with a failure
	}

	// if we make it this far, then age_check() has returned true

	if (purpose_check() == false) { // purpose_check() is in Eligibility.h

		return -1; 
	}

	turn_lights_on(); // in Preparation.h

	start_coding(); // in Code.h

	return 0;
}