typedef struct {
  Point* pickup; /* array of pickup destinations of clients */
  Point* destination; /* array of drop off destinations of clients */
  Point* location; /* where taxi is at current moment */
  int busy;
} TAXI;

typedef struct {
  char name[80]; /* name of client */
  Point* pickup; /* pickup destination */
  Point* destination; /* drop off destination */
  int stand; /* 0 = at a stand, 1 = not at a stand and has to pay base fee */
  char price[80]; /* price of ride */
  int premium; /* 0 = driver can pick up other clients, 1 = client pays extra to make driver have to go straight to destination */
  TAXI* taxi; /* pointer to taxi that is giving the ride */
} CLIENT;
