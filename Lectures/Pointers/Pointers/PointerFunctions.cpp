void ChangePointer(int *p) {
   *p = 1000;
}

void ChangeReference(int &r) {
   r = 2000;
}

void ChangeTwoPointers(int *p1, int *p2) {
   *p1 = -1;
   *p2 = -2;
}