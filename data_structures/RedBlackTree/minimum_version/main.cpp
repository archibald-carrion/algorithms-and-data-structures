// #include "llist.h"
// #include "bstree.h"
// #include "chasht.h"
#include "rbtree.h"
#include <random>
#include <iostream>
#include <ctime>
#include <chrono>

void fillTree(rbtree<int> &tree, int quantityElements){
  // fill the tree with quantityElements random elements
  int min = 0;
  int max = 2*quantityElements;

 // std::srand(static_cast<unsigned>(std::time(nullptr)));

  for (int i = 0; i < quantityElements; i++) {
    // std::cout << "aa" << std::endl;

    //int randomNumber = min + std::rand() % (max - min + 1);
    rbtnode<int> *node = new rbtnode<int>(i, nullptr, nullptr, nullptr, RED);
    // std::cout << "dd" << std::endl;
    tree.Insert(node);


    // std::cout << "bb" << std::endl;
    // rbtnode<int> *search_node = tree.Search(tree.root, 1);
    // std::cout << "cc" << std::endl;
    // std::cout << search_node->key << search_node->color << std::endl;

  }
}

void searchTree(rbtree<int> &tree, int quantityElements) {
  // search in the tree the inserted element and print it
  int min = 0;
  int max = 2*1000000;
  std::srand(static_cast<unsigned>(std::time(nullptr)));

  for (int i = 0; i < quantityElements; i++) {
    int randomNumber = min + std::rand() % (max - min + 1);
    tree.Search(tree.root, randomNumber);
    // search in the table the inserted element and print it
    // std::cout << *table.Search(randomNumber) << std::endl;
  }
}

int main() {
  // chtable<int> table(1000000);
  rbtree<int> tree;
  // llist<int> list;
  int n = 1000000;
  // std::cout << "Tree will be filled" << std::endl;
  fillTree(tree, n);

  rbtnode<int> *node = new rbtnode<int>(1564987, nullptr, nullptr, nullptr, RED);
    // std::cout << "dd" << std::endl;
  tree.Insert(node);
  rbtnode<int> *search_node = tree.Search(tree.root, 1564987);
  // std::cout << search_node << std::endl;
  // std::cout << search_node->key << search_node->color << std::endl;
  // std::cout << tree.root->color << std::endl;

  // tree.InorderWalk(tree.root);
  // std::cout << "Tree filled" << std::endl;

  // rbtnode<int> *node = new rbtnode<int>(1, nullptr, nullptr, nullptr, RED);

  // tree.Insert(node);
  // filltable(table, n);

  auto start_1 = std::chrono::high_resolution_clock::now();
  // n = 180000000;
  n = 100000;

  // searchtable(table, n);
  searchTree(tree, n);
  
  auto end_1 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsed_1 = end_1 - start_1;
  std::cout << "Execution time of searchtable(msec): " << elapsed_1.count() << std::endl;

  return 0;
}

// void searchtable(chtable<int> &table, int n) {

//   // store n random numbers in the table
//   int min = 0;
//   int max = 2*n;
//   std::srand(static_cast<unsigned>(std::time(nullptr)));

//   for (int i = 0; i < n; i++) {
//     int randomNumber = min + std::rand() % (max - min + 1);
//     table.Search(randomNumber);
//     // search in the table the inserted element and print it
//     // std::cout << *table.Search(randomNumber) << std::endl;
//   }
  

// //   for (int i = 0; i < quantityElements; i++) {
// //     // int randomNumber = min + std::rand() % (max - min + 1);
// //     llnode<int> *node = new llnode<int>(i, nullptr, nullptr);
// //     list.Insert(node);
// //   //   llnode<int> *node = new llnode<int>(i, nullptr, nullptr);
// //   //   list.Insert(node);
// //   }

// }


// void filltable(chtable<int> &table, int n) {

//   // store n random numbers in the table
//   int min = 0;
//   int max = 2*n;
//   // std::srand(static_cast<unsigned>(std::time(nullptr)));

//   for (int i = 0; i < n; i++) {
//     // int randomNumber = min + std::rand() % (max - min + 1);
//     // table.Insert(randomNumber);
//     table.Insert(i);

//     // search in the table the inserted element and print it
//     // std::cout << *table.Search(randomNumber) << std::endl;
//   }
  

// //   for (int i = 0; i < quantityElements; i++) {
// //     // int randomNumber = min + std::rand() % (max - min + 1);
// //     llnode<int> *node = new llnode<int>(i, nullptr, nullptr);
// //     list.Insert(node);
// //   //   llnode<int> *node = new llnode<int>(i, nullptr, nullptr);
// //   //   list.Insert(node);
// //   }

// }

// // fill list function
// void fillList(llist<int> &list, int quantityElements) {
//   // fill the list with quantityElements random elements
//   int min = 0;
//   int max = 2*quantityElements;

//   // std::srand(static_cast<unsigned>(std::time(nullptr)));
  

//   for (int i = 0; i < quantityElements; i++) {
//     // int randomNumber = min + std::rand() % (max - min + 1);
//     llnode<int> *node = new llnode<int>(i, nullptr, nullptr);
//     list.Insert(node);
//   //   llnode<int> *node = new llnode<int>(i, nullptr, nullptr);
//   //   list.Insert(node);
//   }
// }

// void searchList(llist<int> &list, int quantityElements) {
//   // fill the list with quantityElements random elements
//   int min = 0;
//   int max = 2*quantityElements;

//   for (int i = 0; i < max; i++) {
//     list.Search(i);
//   }
// }



// void fillTree(bstree<int> &tree, int quantityElements) {
//   // fill the tree with quantityElements random elements
//   int min = 0;
//   int max = 2*quantityElements;

//   std::srand(static_cast<unsigned>(std::time(nullptr)));
  
//   for (int i = 0; i < quantityElements; i++) {
//     int randomNumber = min + std::rand() % (max - min + 1);
//     bstnode<int> *node = new bstnode<int>(randomNumber, nullptr, nullptr);
//     //std::cout<<randomNumber<<" ";
//     tree.Insert(node);
//   }
//   //std::cout<<std::endl;
// }

// void SearchTree(bstree<int> &tree, int quantitySearch){
//   int min = 0;
//   int max = 2*1000000;

//   std::srand(static_cast<unsigned>(std::time(nullptr)));
  
//   for (int i = 0; i < quantitySearch; i++) {
//     int randomNumber = min + std::rand() % (max - min + 1);
//     tree.Search(tree.root, randomNumber);
//   }
// }

// void fillTree(bstree<int> &tree, int quantityElements) {
//   // fill the tree with quantityElements random elements
//   int min = 0;
//   int max = 2*quantityElements;

//   std::srand(static_cast<unsigned>(std::time(nullptr)));
  
//   for (int i = 0; i < quantityElements; i++) {
//     int randomNumber = min + std::rand() % (max - min + 1);
//     bstnode<int> *node = new bstnode<int>(randomNumber, nullptr, nullptr);
//     //std::cout<<randomNumber<<" ";
//     tree.Insert(node);
//   }
//   //std::cout<<std::endl;
// }

// void SearchTree(bstree<int> &tree, int quantitySearch) {
//   int min = 0;
//   int max = 2*1000000;

//   std::srand(static_cast<unsigned>(std::time(nullptr)));
  
//   for (int i = 0; i < quantitySearch; i++) {
//     int randomNumber = min + std::rand() % (max - min + 1);
//     // tree.IterativeSearch(tree.root, i);
//     tree.Search(tree.root, randomNumber);
//   }
// }

// int main(){
//   bstree<int> tree;
//   int n = 1000000;

//   // fillTree(tree, n);
//   tree.fillLinearTree(n);
//   //tree.InorderWalk(tree.root);


//   int n_0 = 86000;
//   auto start_1 = std::chrono::high_resolution_clock::now();
//   // SearchTree(tree, n_0);
//   auto end_1 = std::chrono::high_resolution_clock::now();
//   std::chrono::duration<double, std::milli> elapsed_1 = end_1 - start_1;
//   std::cout << "Execution time of search tree(msec): " << elapsed_1.count() << std::endl;

//   //tree.InorderWalk(tree.root);
//   //std::cout<<std::endl;
//   //std::cout<<"minimum: "  << tree.Minimum(tree.root)->key << std::endl;
//   //std::cout<< "maximum: " << tree.Maximum(tree.root)->key << std::endl;
//   //std::cout<< "root: " << tree.root << std::endl;

//   // std::cout<< "search: "  << tree.Successor(tree.Successor(tree.Minimum(tree.root)))->key << std::endl;
//   // std::cout<< "search: "  << tree.Successor(tree.Maximum(tree.root)) << std::endl;
//   //tree.Delete(tree.root->right);
//   //std::cout<< "root: " << tree.root << std::endl;
  
//   //tree.InorderWalk(tree.root);



//   // do search in the tree

//   return 0;
// }

// // fill list function
// void fillList(llist<int> &list, int quantityElements) {
//   // fill the list with quantityElements random elements
//   int min = 0;
//   int max = 2*quantityElements;

//   // std::srand(static_cast<unsigned>(std::time(nullptr)));
  

//   for (int i = 0; i < quantityElements; i++) {
//     // int randomNumber = min + std::rand() % (max - min + 1);
//     llnode<int> *node = new llnode<int>(i, nullptr, nullptr);
//     list.Insert(node);
//   //   llnode<int> *node = new llnode<int>(i, nullptr, nullptr);
//   //   list.Insert(node);
//   }
// }

// void searchList(llist<int> &list, int quantityElements) {
//   // fill the list with quantityElements random elements
//   int min = 0;
//   int max = 2*quantityElements;

//   for (int i = 0; i < max; i++) {
//     list.Search(i);
//   }
// }

// int main() {
//   llist<int> list;
//   int n = 1000000;

//   auto start_0 = std::chrono::high_resolution_clock::now();
//   fillList(list, n);
//   auto end_0 = std::chrono::high_resolution_clock::now();
//   std::chrono::duration<double, std::milli> elapsed_0 = end_0 - start_0;
//   std::cout << "Execution time of fillList(msec): " << elapsed_0.count() << std::endl;


//   n = 1600;
//   auto start_1 = std::chrono::high_resolution_clock::now();
//   searchList(list, n);
//   auto end_1 = std::chrono::high_resolution_clock::now();
//   std::chrono::duration<double, std::milli> elapsed_1 = end_1 - start_1;
//   std::cout << "Execution time of searchList(msec): " << elapsed_1.count() << std::endl;


//   // list.printList();
//   return 0;
// }

