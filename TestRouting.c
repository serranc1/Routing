#include <stdio.h>
#include <stdlib.h>

int movearray[7];
int maparray[4][3] = {{0, 0, 0},{0, 1, 1},{0, 1, 1},{0, 0, 0}};
int rows = 4;
int columns = 3;

/* a and b are initial y and x respectively; c and d are final y and x respectively */

float CalculateDistance(int a, int b, int c, int d, float distance) {
  float distancer = distance;
  float distancef = distance;
  float verticalf = 0;
  float horizontalf = 0;
  float vertical1 = 0;
  float vertical2 = 0;
  float horizontal1 = 0;
  float horizontal2 = 0;
  int h, i;
  int h1 = a;
  int i1 = b;
  int h2 = a;
  int i2 = b;
  int e = c - a;
  int f = d - b;
  int movearray1[rows+columns]; /* array for displaying move order of taxi; 1 = up, 2 = right, 3 = down, 4 = left */
  int movearray2[rows+columns];
  int arrayposition1 = 0;
  int arrayposition2 = 0;
  int arrayposition = 0;
  int positiontemp = 0;
  while(a != c || b != d) {
    for(arrayposition; arrayposition < sizeof(movearray)/sizeof(int); arrayposition++) {
      if(movearray[arrayposition] == 0) {
        printf("Found array position to start editing at %d!\n", arrayposition);
        break;
      }
      else {
        continue;
      }
    }
	  if(e < 0) { /* abs */
		  e = -e;
	  }
	  if(f < 0) { /* abs */
		  f = -f;
	  }
	  if(e >= f) { /* if vertical distance >= horizontal distance */
      printf("vertical distance >= horizontal distance,\n");
		  if(a < c) { /* if initial y is above final y */
        printf("Initial y is above final y.\n");
        printf("Route 1:\n");
        for(h1; h1 < c; h1++) { /* moving down */
          printf("moving down.\n");
				  if(maparray[h1+1][i1] == 1){ /* if path obstructed */
            printf("Path obstructed!\n");
					  break;
				  }
				  else {
	    				vertical1 += 0.25;
              printf("vertical 1 is now %f.\n", vertical1);
              movearray1[arrayposition1] = 3;
              printf("Move array 1 position %d is %d.\n", arrayposition1, movearray1[arrayposition1]);
              arrayposition1++;
              printf("Array position 1 is now %d.\n", arrayposition1);
	  			}
        }
        printf("Reached end of moving vertically. Moving horizontally...\n");
        if(i1+1 > columns-1) {
          horizontal1 = 100;
          printf("Path goes out of map!\n");
        }
			  for(i1; maparray[h1][i1+1] == 0; i1++) { /* moving right */
          printf("moving right.\n");
				  if(maparray[h1][i1+1] == 1){ /* if path obstructed */
            printf("Path obstructed!\n");
            break;
				  }
          if(h1 == c && i1 == d) {
            break;
          }
				  else {
            if(h1 == c && i1 == d) {
              break;
            }
            if(i1+1 > columns-1) {
              horizontal1 = 100;
              printf("Path goes out of map!\n");
              break;
            }
					  if(maparray[h1+1][i1+1] == 0 && maparray[h1+1][i1] == 1) { /* check if going to be at corner of obstacle */
              printf("Reached corner of obstacle!\n");
						  horizontal1 += 0.25;
              printf("horizontal 1 is now %f.\n", horizontal1);
						  i1++;
              movearray1[arrayposition1] = 2;
              printf("Move array 1 position %d is %d.\n", arrayposition1, movearray1[arrayposition1]);
              arrayposition1++;
              printf("Array position 1 is now %d.\n", arrayposition1);
						  break;
					  }
					  else {
						  horizontal1 += 0.25;
              printf("horizontal 1 is now %f.\n", horizontal1);
              movearray1[arrayposition1] = 2;
              printf("Move array 1 position %d is %d.\n", arrayposition1, movearray1[arrayposition1]);
              arrayposition1++;
              printf("Array position 1 is now %d.\n", arrayposition1);
              if(arrayposition1 > sizeof(movearray)/sizeof(int)) {
                horizontal1 = 100;
                break;
              }
					  }
    			}
  			}
        printf("Route 2:\n");
  			for(h2; h2 < c; h2++) { /* moving down */
          printf("moving down.\n");
				  if(maparray[h2+1][i2] == 1){ /* if path obstructed */
            printf("Path obstructed!\n");
					  break;
				  }
				  else {
					  vertical2 += 0.25;
            printf("vertical 2 is now %f.\n", vertical2);
            movearray2[arrayposition2] = 3;
            printf("Move array 2 position %d is %d.\n", arrayposition2, movearray2[arrayposition2]);
            arrayposition2++;
            printf("Array position 2 is now %d.\n", arrayposition2);
 			    }
			  }
        printf("Reached end of moving vertically. Moving horizontally...\n");
        if(i2-1 < 0) {
          horizontal2 = 100;
          printf("Path goes out of map!\n");
        }
			  for(i2; maparray[h2][i2-1] == 0; i2--) { /* moving left */
          printf("moving left.\n");
				  if(maparray[h2][i2-1] == 1){ /* if path obstructed */
            printf("Path obstructed!\n");
					  break;
				  }
          if(h2 == c && i2 == d) {
            break;
          }
				  else {
            if(h2 == c && i2 == d) {
              break;
            }
            if(i2-1 < 0) {
              horizontal2 = 100;
              printf("Path goes out of map!\n");
              break;
            }
					  if(maparray[h2+1][i2-1] == 0 && maparray[h2+1][i2] == 1) { /* check if going to be at corner of obstacle */
              printf("Reached corner of obstacle!\n");
						  horizontal2 += 0.25;
              printf("horizontal 2 is now %f.\n", horizontal2);
						  i2--;
              movearray2[arrayposition2] = 4;
              printf("Move array 2 position %d is %d.\n", arrayposition2, movearray2[arrayposition2]);
              arrayposition2++;
              printf("Array position 2 is now %d.\n", arrayposition2);
						  break;
					  }
					  else {
						  horizontal2 += 0.25;
              printf("horizontal 2 is now %f.\n", horizontal2);
              movearray2[arrayposition2] = 4;
              printf("Move array 2 position %d is %d.\n", arrayposition2, movearray2[arrayposition2]);
              arrayposition2++;
              printf("Array position 2 is now %d.\n", arrayposition2);
              if(arrayposition2 > sizeof(movearray)/sizeof(int)) {
                horizontal2 = 100;
                break;
              }
					  }
 			    }
		    }
      }
		  if(a > c) { /* if initial y is below final y */
        printf("Initial y is below final y.\n");
        printf("Route 1:\n");
			  for(h1; h1 > c; h1--) { /* moving up */
				  if(maparray[h1-1][i1] == 1){ /* if path obstructed */
            printf("Path obstructed!\n");
					  break;
				  }
				  else {
  				  vertical1 += 0.25;
            printf("vertical 1 is now %f.\n", vertical1);
            movearray1[arrayposition1] = 1;
            printf("Move array 1 position %d is %d.\n", arrayposition1, movearray1[arrayposition1]);
            arrayposition1++;
            printf("Array position 1 is now %d.\n", arrayposition1);
 			    }
			  }
        printf("Reached end of moving vertically. Moving horizontally...\n");
        if(i1+1 > columns-1) {
          horizontal1 = 100;
          printf("Path goes out of map!\n");
        }
			  for(i1; maparray[h1][i1+1] == 0; i1++) { /* moving right */
          printf("moving right.\n");
				  if(maparray[h1][i1+1] == 1){  /* if path obstructed */
            printf("Path obstructed!\n");
			  		break;
				  }
				  else {
            if(h1 == c && i1 == d) {
              break;
            }
            if(i1+1 > columns-1) {
              horizontal1 = 100;
              printf("Path goes out of map!\n");
              break;
            }
					  if(maparray[h1-1][i1+1] == 0 && maparray[h1-1][i1] == 1) { /* check if going to be at corner of obstacle */
              printf("Reached corner of obstacle!\n");
						  horizontal1 += 0.25;
              printf("horizontal 1 is now %f.\n", horizontal1);
						  i1++;
              movearray1[arrayposition1] = 2;
              printf("Move array 1 position %d is %d.\n", arrayposition1, movearray1[arrayposition1]);
              arrayposition1++;
              printf("Array position 1 is now %d.\n", arrayposition1);
						  break;
					  }
					  else {
						  horizontal1 += 0.25;
              printf("horizontal 1 is now %f.\n", horizontal1);
              movearray1[arrayposition1] = 2;
              printf("Move array 1 position %d is %d.\n", arrayposition1, movearray1[arrayposition1]);
              arrayposition1++;
              printf("Array position 1 is now %d.\n", arrayposition1);
              if(arrayposition1 > sizeof(movearray)/sizeof(int)) {
                horizontal1 = 100;
                break;
              }
					  }
  			  }
		    }
        printf("Route 2:\n");
 			  for(h2; h2 > c; h2--) { /* moving up */
          printf("moving up.\n");
				  if(maparray[h2-1][i2] == 1){ /* if path obstructed */
            printf("Path obstructed!\n");
					  break;
				  }
				  else {
					  vertical2 += 0.25;
            printf("vertical 2 is now %f.\n", vertical2);
            movearray2[arrayposition2] = 1;
            printf("Move array 2 position %d is %d.\n", arrayposition2, movearray2[arrayposition2]);
            arrayposition2++;
            printf("Array position 2 is now %d.\n", arrayposition2);
    			}
			  }
        printf("Reached end of moving vertically. Moving horizontally...\n");
        if(i2-1 < 0) {
          horizontal2 = 100;
          printf("Path goes out of map!\n");
        }
			  for(i2; maparray[h2-1][i2] == 0; i2--) { /*moving left */
          printf("moving left.\n");
				  if(maparray[h2][i2-1] == 1){ /* if path obstructed */
            printf("Path obstructed!\n");
					  break;
				  }
          if(h2 == c && i2 == d) {
            break;
          }
				  else {
            if(h2 == c && i2 == d) {
              break;
            }
            if(i2-1 < 0) {
              horizontal2 = 100;
              printf("Path goes out of map!\n");
              break;
            }
					  if(maparray[h2-1][i2-1] == 0 && maparray[h2-1][i2] == 1) { /* check if going to be at corner of obstacle */
              printf("Reached corner of obstacle!\n");
						  horizontal2 += 0.25;
              printf("horizontal 2 is now %f.\n", horizontal2);
						  i2--;
              movearray2[arrayposition2] = 4;
              printf("Move array 2 position %d is %d.\n", arrayposition2, movearray2[arrayposition2]);
              arrayposition2++;
              printf("Array position 2 is now %d.\n", arrayposition2);
						  break;
					  }
					  else {
						  horizontal2 += 0.25;
              printf("horizontal 2 is now %f.\n", horizontal2);
              movearray2[arrayposition2] = 4;
              printf("Move array 2 position %d is %d.\n", arrayposition2, movearray2[arrayposition2]);
              arrayposition2++;
              printf("Array position 2 is now %d.\n", arrayposition2);
              if(arrayposition2 > sizeof(movearray)/sizeof(int)) {
                horizontal2 = 100;
                break;
              }
					  }
 			    }
 			  }
		  }
    }
	  else {
      printf("vertical distance < horizontal distance,\n");
		  if(b < d) {
        printf("Initial x is left of final x.\n");
        printf("Route 1:\n");
			  for(i1; i1 < d; i1++) { /* moving right */
          printf("moving right.\n");
				  if(maparray[h1][i1+1] == 1){ /* if path obstructed */
            printf("Path obstructed!\n");
					  break;
	    		}
				  else {
   			    horizontal1 += 0.25;
            printf("horizontal 1 is now %f.\n", horizontal1);
            movearray1[arrayposition1] = 2;
            printf("Move array 1 position %d is %d.\n", arrayposition1, movearray1[arrayposition1]);
            arrayposition1++;
            printf("Array position 1 is now %d.\n", arrayposition1);
    		  }
			  }
        printf("Reached end of moving horizontally. Moving vertically...\n");
        if(h1+1 > rows-1) {
          vertical1 = 100;
          printf("Path goes out of map!\n");
        }
			  for(h1; maparray[h1+1][i1] == 0; h1++) { /*moving down */
          printf("moving down.\n");
				  if(maparray[h1+1][i1] == 1){ /* if path obstructed */
            printf("Path obstructed!\n");
					  break;
	    		}
          if(h1 == c && i1 == d) {
            break;
          }
				  else {
            if(h1 == c && i1 == d) {
              break;
            }
            if(h1+1 > rows-1) {
              vertical1 = 100;
              printf("Path goes out of map!\n");
              break;
            }
					  if(maparray[h1+1][i1+1] == 0 && maparray[h1][i1+1] == 1) { /* check if going to be at corner of obstacle */
              printf("Reached corner of obstacle!\n");
						  vertical1 += 0.25;
              printf("vertical 1 is now %f.\n", vertical1);
						  h1++;
              movearray1[arrayposition1] = 3;
              printf("Move array 1 position %d is %d.\n", arrayposition1, movearray1[arrayposition1]);
              arrayposition1++;
              printf("Array position 1 is now %d.\n", arrayposition1);
						  break;
					  }
					  else {
						  vertical1 += 0.25;
              printf("vertical 1 is now %f.\n", vertical1);
              movearray1[arrayposition1] = 3;
              printf("Move array 1 position %d is %d.\n", arrayposition1, movearray1[arrayposition1]);
              arrayposition1++;
              printf("Array position 1 is now %d.\n", arrayposition1);
              if(arrayposition1 > sizeof(movearray)/sizeof(int)) {
                vertical1 = 100;
                break;
              }
					  }
  			  }
			  }
        printf("Route 2:\n");
			  for(i2; i2 < d; i2++) { /* moving right */
          printf("moving right.\n");
				  if(maparray[h2][i2+1] == 1){ /* if path obstructed */
            printf("Path obstructed!\n");
					  break;
	    		}
				  else {
   			    horizontal2 += 0.25;
            printf("horizontal 2 is now %f.\n", horizontal2);
            movearray2[arrayposition2] = 2;
            printf("Move array 2 position %d is %d.\n", arrayposition2, movearray2[arrayposition2]);
            arrayposition2++;
            printf("Array position 2 is now %d.\n", arrayposition2);
    		  }
			  }
        printf("Reached end of moving horizontally. Moving vertically...\n");
        if(h2-1 < 0) {
          vertical2 = 100;
          printf("Path goes out of map!\n");
        }
			  for(h2; maparray[h2-1][i2] == 0; h2--) { /* moving up */
          printf("moving up.\n");
				  if(maparray[h2-1][i2] == 1){ /* if path obstructed */
            printf("Path obstructed!\n");
					  break;
	    		}
          if(h2 == c && i2 == d) {
            break;
          }
				  else {
            if(h2 == c && i2 == d) {
              break;
            }
            if(h2-1 < 0) {
              vertical2 = 100;
              printf("Path goes out of map!\n");
              break;
            }
					  if(maparray[h2-1][i2+1] == 0 && maparray[h2][i2+1] == 1) { /* check if going to be at corner of obstacle */
              printf("Reached corner of obstacle!\n");
						  vertical2 += 0.25;
              printf("vertical 2 is now %f.\n", vertical2);
						  h2--;
              movearray2[arrayposition2] = 1;
              printf("Move array 2 position %d is %d.\n", arrayposition2, movearray2[arrayposition2]);
              arrayposition2++;
              printf("Array position 2 is now %d.\n", arrayposition2);
						  break;
					  }
					  else {
						  vertical2 += 0.25;
              printf("vertical 2 is now %f.\n", vertical2);
              movearray2[arrayposition2] = 1;
              printf("Move array 2 position %d is %d.\n", arrayposition2, movearray2[arrayposition2]);
              arrayposition2++;
              printf("Array position 2 is now %d.\n", arrayposition2);
              if(arrayposition2 > sizeof(movearray)/sizeof(int)) {
                vertical2 = 100;
                break;
              }
					  }
    			}
			  }
		  }
		  if(b > d) {
        printf("Initial x is right of final x.\n");
        printf("Route 1:\n");
			  for(i1; i1 > d; i1--) { /* moving left */
          printf("moving left.\n");
				  if(maparray[h1][i1-1] == 1){ /* if path obstructed */
            printf("Path obstructed!\n");
					  break;
   		    }
				  else {
   			    horizontal1 += 0.25;
            printf("horizontal 1 is now %f.\n", horizontal1);
            movearray1[arrayposition1] = 4;
            printf("Move array 1 position %d is %d.\n", arrayposition1, movearray1[arrayposition1]);
            arrayposition1++;
            printf("Array position 1 is now %d.\n", arrayposition1);
    		  }
			  }
        printf("Reached end of moving horizontally. Moving vertically...\n");
        if(h1+1 > rows-1) {
          vertical1 = 100;
          printf("Path goes out of map!\n");
        }
			  for(h1; maparray[h1+1][i1] == 0; h1++) { /* moving down */
          printf("moving down.\n");
				  if(maparray[h1+1][i1] == 1){ /* if path obstructed */
            printf("Path obstructed!\n");
					  break;
	    		}
          if(h1 == c && i1 == d) {
            break;
          }
				  else {
            if(h1 == c && i1 == d) {
              break;
            }
            if(h1+1 > rows-1) {
              vertical1 = 100;
              printf("Path goes out of map!\n");
              break;
            }
					  if(maparray[h1+1][i1-1] == 0 && maparray[h1][i1-1] == 1) { /* check if going to be at corner of obstacle */
              printf("Reached corner of obstacle!\n");
						  vertical1 += 0.25;
              printf("vertical 1 is now %f.\n", vertical1);
						  h1++;
              movearray1[arrayposition1] = 3;
              printf("Move array 1 position %d is %d.\n", arrayposition1, movearray1[arrayposition1]);
              arrayposition1++;
              printf("Array position 1 is now %d.\n", arrayposition1);
						  break;
					  }
					  else {
						  vertical1 += 0.25;
              printf("vertical 1 is now %f.\n", vertical1);
              movearray1[arrayposition1] = 3;
              printf("Move array 1 position %d is %d.\n", arrayposition1, movearray1[arrayposition1]);
              arrayposition1++;
              printf("Array position 1 is now %d.\n", arrayposition1);
              if(arrayposition1 > sizeof(movearray)/sizeof(int)) {
                vertical1 = 100;
                break;
              }
					  }
    			}
			  }
        printf("Route 2:\n");
			  for(i2; i2 > d; i2--) { /* moving left */
          printf("moving left.\n");
				  if(maparray[h2][i2-1] == 1){ /* if path obstructed */
            printf("Path obstructed!\n");
					  break;
	    		}
				  else {
   			    horizontal2 += 0.25;
            printf("horizontal 2 is now %f.\n", horizontal2);
            movearray2[arrayposition2] = 4;
            printf("Move array 2 position %d is %d.\n", arrayposition2, movearray2[arrayposition2]);
            arrayposition2++;
            printf("Array position 2 is now %d.\n", arrayposition2);
    		  }
			  }
        printf("Reached end of moving horizontally. Moving vertically...\n");
        if(h2-1 < 0) {
          vertical2 = 100;
          printf("Path goes out of map!\n");
        }
			  for(h2; maparray[h2-1][i2] == 0; h2--) { /* moving up */
          printf("moving up.\n");
				  if(maparray[h2-1][i2] == 1){ /* if path obstructed */
            printf("Path obstructed!\n");
					  break;
	    		}
          if(h2 == c && i2 == d) {
            break;
          }
				  else {
            if(h2 == c && i2 == d) {
              break;
            }
            if(h2-1 < 0) {
              vertical2 = 100;
              printf("Path goes out of map!\n");
              break;
            }
					  if(maparray[h2-1][i2-1] == 0 && maparray[h2][i2-1] == 1) { /* check if going to be at corner of obstacle */
              printf("Reached corner of obstacle!\n");
						  vertical2 += 0.25;
              printf("vertical 2 is now %f.\n", vertical2);
						  h2--;
              movearray2[arrayposition2] = 1;
              printf("Move array 2 position %d is %d.\n", arrayposition2, movearray2[arrayposition2]);
              arrayposition2++;
              printf("Array position 2 is now %d.\n", arrayposition2);
						  break;
					  }
					  else {
						  vertical2 += 0.25;
              printf("vertical 2 is now %f.\n", vertical2);
              movearray2[arrayposition2] = 1;
              printf("Move array 2 position %d is %d.\n", arrayposition2, movearray2[arrayposition2]);
              arrayposition2++;
              printf("Array position 2 is now %d.\n", arrayposition2);
              if(arrayposition2 > sizeof(movearray)/sizeof(int)) {
                vertical2 = 100;
                break;
              }
					  }
    			}
			  }
		  }			
	  }
    printf("Finished route generation!\n");
	  if(vertical1 * vertical1 + horizontal1 * horizontal1 <= vertical2 * vertical2 + horizontal2 * horizontal2) {
		  verticalf += vertical1;
		  horizontalf += horizontal1;
      h = h1;
      i = i1;
      printf("Route 1 was selected!\n");
      for(arrayposition; movearray1[positiontemp] == 1 || movearray1[positiontemp] == 2 || movearray1[positiontemp] == 3 || movearray1[positiontemp] == 4; arrayposition++) {
        movearray[arrayposition] = movearray1[positiontemp];
        printf("Move array position %d is %d.\n", arrayposition, movearray[arrayposition]);
        positiontemp++;
      }
	  }
	  else {
		  verticalf += vertical2;
		  horizontalf += horizontal2;
      h = h2;
      i = i2;
      printf("Route 2 was selected!\n");
      for(arrayposition; movearray2[positiontemp] == 1 || movearray2[positiontemp] == 2 || movearray2[positiontemp] == 3 || movearray2[positiontemp] == 4; arrayposition++) {
        movearray[arrayposition] = movearray2[positiontemp];
        printf("Move array position %d is %d.\n", arrayposition, movearray[arrayposition]);
        positiontemp++;
      }
	  }
    printf("Calculating distance of chosen route...\n");
    distancef += verticalf + horizontalf;
    printf("Calculated distance of current route is %f miles.\n", distancef);
	  distancer = CalculateDistance(h, i, c, d, distancef);
    break;
  }
  return distancer;
}

int main() {
  printf("Starting the test.\n");
  int a = 0;
  int b = 1;
  int c = 3;
  int d = 2;
  float distance = 0;
  int i;
  float testdistance = CalculateDistance(a, b, c, d, distance);
  printf("The total distance traveled is %f\n", testdistance);
  printf("Printing move list...\n");
  for(i = 0; i < sizeof(movearray)/sizeof(int); i++) {
    if(movearray[i] == 1) {
      printf("UP\n");
    }
    else if(movearray[i] == 2) {
      printf("RIGHT\n");
    }
    else if(movearray[i] == 3) {
      printf("DOWN\n");
    }
    else if(movearray[i] == 4) {
      printf("LEFT\n");
    }
    else {
      printf("FINISHED\n");
    }
  }
  return 1;
}
  
