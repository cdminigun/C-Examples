#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
  graphT myg1, *myg2=NULL;
  initialize_graph(&myg1, FALSE);
  read_graph(&myg1, FALSE);
  print_graph(&myg1);
  copy_graph_list(&myg1, &myg2);
  print_graph(myg2);
  free(myg2);
}
void copy_graph_list(graphT *g, graphT **newg)
{
  graphT *tmpG;
  edgenodeT *pe;
  int i, j;
  tmpG = (graphT *) malloc(sizeof(graphT));
  if(tmpG==NULL) {
    printf("no memory");
    exit(-1);
  }
  if(!g)
    return;
  initialize_graph(tmpG, FALSE);
  for(i=1; i<g->nvertices+1;i++)
  {
    pe = g->edges[i];
    while(pe != NULL){

      edgenodeT *ge, *pe2;
      int test = 1;
      ge = malloc(sizeof(edgenodeT));
      ge->weight = pe->weight;
      ge->y = pe->y;
      pe2 = tmpG->edges[i];
      if(pe2 == NULL)
      {
        ge->next = tmpG->edges[i];
        tmpG->edges[i] = ge;
        tmpG->degree[i]++;
        tmpG->nedges ++;
      }
      else
      {
        while(pe2 != NULL && test == 1)
        {
          if(pe2->next == NULL)
          {
            ge->next = NULL;
            pe2->next = ge;
            tmpG->degree[i]++;
            tmpG->nedges ++;
            test = 0;
          }
        pe2 = pe2->next;
      }
    }
      pe = pe->next;
    }
  }
  tmpG->nvertices = g->nvertices;
  tmpG->directed = g->directed;
  *newg = tmpG;
}
void print_graph(graphT *g)
{
 edgenodeT *pe;
 int i;
 if(!g) return;
 for(i=1; i<=g->nvertices; i++) {
 printf("Node %d: ", i);
 pe = g->edges[i];
 while(pe){
 // printf(" %d", pe->y);
 printf(" %d(w=%d),", pe->y, pe->weight);
 pe = pe->next;
 }
 printf("\n");
 }
}
void initialize_graph(graphT *g, bool directed)
{
 int i;
 g->nvertices = 0;
 g->nedges = 0;
 g->directed = directed;
 for (i=1; i<=MAXV; i++)
 g->edges[i] = NULL;
 for (i=1; i<=MAXV; i++)
 g->degree[i] = 0;
}
void read_graph(graphT *g, bool directed)
{
 int i;
 int m;
 int x, y, w;
 scanf("%d %d",&(g->nvertices),&m);

 for (i=1; i<=m; i++) {
 scanf("%d %d %d",&x,&y, &w);
 insert_edge(g, x, y, w, directed);
 }
}
void insert_edge(graphT *g, int x, int y, int w, bool directed)
{
 edgenodeT *pe;
 pe = malloc(sizeof(edgenodeT));
 pe->weight = w;
 pe->y = y;
 pe->next = g->edges[x];
 g->edges[x] = pe;
 g->degree[x]++;
 if (directed == FALSE)
 insert_edge(g, y, x, w, TRUE);
 else
 g->nedges ++;
}
void free_graph(graphT *g)
{
 edgenodeT *pe, *olde;
 int i;
 for(i=1; i<=g->nvertices; i++) {
 pe = g->edges[i];
 while(pe){
 olde = pe;
 pe = pe->next;
 free(olde);
 }
 }
 free(g);
}
