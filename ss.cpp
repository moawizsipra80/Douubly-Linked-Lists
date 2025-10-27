	// DNode<T>* reverseFrom(DNode<T>* start) {
	// 	DNode<T>* curr = start;
	// 	DNode<T>* last = nullptr;
	// 	while (curr) {
	// 		DNode<T>* nxt = curr->next;
	// 		curr->next = curr->prev;
	// 		curr->prev = nxt;
	// 		last = curr;
	// 		curr = nxt;
	// 	}
	// 	return last; // new head of this reversed chain




    // }





	// void merge(LDLL<T>& other) {
	// 	if (!other.head) return;
	// 	if (!head) {
	// 		head = other.head;
	// 		tail = other.tail;
	// 	} else {
	// 		tail->next = other.head;
	// 		other.head->prev = tail;
	// 		tail = other.tail;
	// 	}
	// 	other.head = other.tail = nullptr;
	// }













    	// Swap nodes by swapping their values
	// void swapNodes(T val1, T val2) {
	// 	if (val1 == val2) return;
	// 	DNode<T>* n1 = head;
	// 	DNode<T>* n2 = head;
	// 	while (n1 && n1->info != val1) n1 = n1->next;
	// 	while (n2 && n2->info != val2) n2 = n2->next;
	// 	if (!n1 || !n2) return;
	// 	T tmp = n1->info; n1->info = n2->info; n2->info = tmp;
	// }

	// // Simple bubble sort by data values
	// void sort() {
	// 	if (!head || !head->next) return;
	// 	bool swapped;
	// 	do {
	// 		swapped = false;
	// 		for (DNode<T>* i = head; i && i->next; i = i->next) {
	// 			if (i->info > i->next->info) {
	// 				T tmp = i->info; i->info = i->next->info; i->next->info = tmp;
	// 				swapped = true;
	// 			}
	// 		}
	// 	} while (swapped);
	// }
