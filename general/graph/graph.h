typedef enum {FALSE, TRUE} bool;
#define MAXV 100
typedef struct edgenode {
 int y;
 int weight;
 struct edgenode *next;
} edgenodeT;
typedef struct {
 edgenodeT *edges[MAXV+1];
 int degree[MAXV+1];
 int nvertices;
 int nedges;
 bool directed;
} graphT;

void copy_graph_list(graphT *g, graphT **newg);
void print_graph(graphT *g);
void initialize_graph(graphT *g, bool directed);
void read_graph(graphT *g, bool directed);
void insert_edge(graphT *g, int x, int y, int w, bool directed);
void free_graph(graphT *g);
