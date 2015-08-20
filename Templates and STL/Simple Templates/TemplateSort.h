#ifndef __TEMPLATESORT_H
#define __TEMPLATESORT_H

// Templated Insertion Sort.
template<typename T>
void SortArray(T *data) {
   for (int i = 1; i < 10; i++) {
      T elementI = data[i];
      int j;
      for (j = i; j > 0; j--) {
         if (elementI < data[j - 1]) {
            data[j] = data[j - 1];
         }
         else {
            break;
         }
      }
      data[j] = elementI;
   }
}
// What types can T be?

#endif