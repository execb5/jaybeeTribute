
typedef enum {false, true} bool;

struct Node
{
	int val;
	struct Node* next;
};

typedef struct
{
	struct Node* head;
	struct Node* current;
	int size;
} List;

bool deleteAux(List* list, int val, struct Node* node, struct Node* prev);
bool del(List* list, int val);
int getVal(List* list, int index);
int maxAux(struct Node* node);
int max(List* list);
List copy(List* list);
struct Node* addToList(List* list, int val, bool addToEnd);
struct Node* createList(List* list, int val);
void initializeList(List* list);
void destroyAux(struct Node* node);
void destroyList(List* list);
void printAux(struct Node* node);
void print(List* list);
