#include "laps.h"

/**
 * race_state - keeps track of the number of
 *    laps made by several cars in a race.
 * @id: id of each car which is an arr of int
 * @size: size of this array
 * return: the race state
 */
void race_state(int *id, size_t size)
{
	static int cars[64];
	static int laps[64];
	static size_t count;
	int exists;
	size_t i, j;

	if (!size)
		return;
	for (i = 0; i < size; i++)
	{
		exists = 0;
		for (j = 0; j < count; j++)
		{
			if (id[i] == cars[j])
			{
				exists = 1;
				laps[j] += 1;
				break;
			}
		}
		if (exists == 0)
		{
			cars[count] = id[i];
			sort_car(cars, laps, count);
			count++;
			printf("Car %d joined the race\n", id[i]);
		}
	}
	printf("Race state:\n");
	for (j = 0; j < count; j++)
	{
		printf("Car %d [%d laps]\n", cars[j], laps[j]);
	}
}


/**
 * sort_car - fn to sort cars.
 * @cars: array of cars
 * @laps: array of laps
 * @count: number of cars in the race
 * Return: no return value.
 */
void sort_car(int *cars, int *laps, int count)
{
	int x, tmp = 0;

	for (x = count; x > 0; x--)
	{
		if (cars[x] < cars[x - 1])
		{
			tmp = cars[x - 1];
			cars[x - 1] = cars[x];
			cars[x] = tmp;
			tmp = laps[x - 1];
			laps[x - 1] = laps[x];
			laps[x] = tmp;
		}
	}
}
