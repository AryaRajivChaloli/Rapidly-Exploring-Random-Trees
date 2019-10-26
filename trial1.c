#include<math.h>
#define EPSILON 2

struct node {
	int x_coord;
	int y_coord;
	struct node *parent_node;
	struct node *next_in_list;
} NODE;

struct tree_nodes {
	int no_of_nodes;
	node *list_head;
} TREE_NODES;

int dist_between(NODE *p1,NODE *p2) {
	x1 = p1->x_coord;
	x2 = p2->x_coord;
	y1 = p1->y_coord;
	y2 = p2->y_coord;
	dist = sqrt(pow((x1-x2),2)+pow((y1-y2),2));
	dist = (int)dist;
	return dist;
}

NODE* find_nearest_node(TREE_NODES *tn, int new_point_x, int new_point_y) {
	n = tn->no_of_nodes;
	curr_node = tn->list_head;
	NODE *temp = (NODE*)malloc(sizeof(NODE));
	temp->x_coord = new_point_x;
	temp->y_coord = new_point_y;
	int min_dist = dist_between(curr_node, temp);
	NODE *nearest_node = curr_node;
	curr_node = curr_node->next_in_list;
	for (int i=1; i<n; i++)
		if min_dist>dist_between(curr_node, temp)
			nearest_node = curr_node;
		curr_node = curr_node->next_in_list;
	return nearest_node;
}

init_tree(tn, start_x, start_y);
choose_point(tn);
adjust_len(newnode, nearest);
path_clear(nearest, newnode, obst_list)
void add_to_tree(NODE *nearest, int *newnode, TREE *tn, NODE *added_node) {
    NODE *temp = (NODE*)malloc(sizeof(NODE));
	temp->x_coord = newnode[0];
	temp->y_coord = newnode[1];
    temp->parent_node = nearest;
    temp->next_in_list = nearest->next_in_list;
    nearest->next_in_list = temp;
    added_node = temp;
}

int not_equal(NODE *added_node, int end_x, int end_y) {
    return ((added_node->x_coord == end_x)(added_node->y_coord == end_y));
}

int main() {
	int n_cols;
	int n_rows;
	scanf("%d", n_cols);
	scanf("%d", n_rows);
	int start_x;
	int start_y;
	scanf("%d", start_x);
	scanf("%d", start_y);
	int end_x;
	int end_y;
	scanf("%d", end_x);
	scanf("%d", end_y);
	int no_obst;
	scanf("%d", no_obst);
	int obst_list[no_obst][2];
	for (int i=0; i<no_obst; i++) {
		scanf("%d", obst_list[i][0]);
		scanf("%d", obst_list[i][1]);
	}
	
	TREE_NODES *tn;
	init_tree(tn, start_x, start_y);
	
	int newnode[2];
	NODE* nearest;
	int iter = 0;
	NODE* added_node = NULL;
	
	do {
	    newnode = choose_point(tn);
		nearest = find_nearest_node(tn, newnode[0], newnode[1]);
		newnode = adjust_len(newnode, nearest);
		if (path_clear(nearest, newnode, obst_list))
			add_to_tree(nearest, newnode, tn, added_node);
		iter+=1;
	} while(not_equal(added_node, end_x, end_y) && iter<=10000) 
	return 0;
}