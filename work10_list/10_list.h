struct animal{
  int num_legs;
  char name[20];
  struct animal *next;
};

void print_struct(struct animal *p);

struct animal * make_struct(int l, char *n);

void print_list(struct animal *p);

struct animal * insert_front(struct animal *p, int l, char *n);

struct animal * free_list(struct animal *p);

struct animal * remove_animal(struct animal *front, int data);
