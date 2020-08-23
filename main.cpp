#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>

#define MIN_RANGE 20000
#define MAX_RANGE 60000
#define BLAST_RADIUS 100
#define MAX_AMMO 6

int main() {
	srand(time(NULL));
	int ammo = MAX_AMMO;
	int range = MIN_RANGE + (rand() % (MAX_RANGE - MIN_RANGE));
	int target = 0.1 * range + (rand() % (int)(0.8 * range));
	printf("Your gun has %d rounds of ammunition.\n", ammo);
	printf("Maximum range of your gun is %d yards.\n", range);
	printf("Distance to the target is %d yards.\n", target);
	while (ammo > 0) {
		double elev;
		printf("%d. round in chamber.\n", (MAX_AMMO - ammo) + 1);
		do {
			printf("Gun elevation in degrees (1-89)? ");
			scanf("%lf", &elev);
		} while (elev < 1.0 || elev > 89.0);
		--ammo;
		double impact = range * sin(2.0 * elev * M_PI / 180.0);
		double impact_distance = abs(impact - target);
		if (impact_distance < BLAST_RADIUS) {
			printf("Target destroyed!\n");
			return 0;
		}
		printf("%s target by %.0f yards\n", (impact > target) ? "Over" : "Short of", impact_distance);
	}
	printf("Out of ammo! The enemy destroyed you!\n");
	return 0;
}
