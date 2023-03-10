/*****************************************************************
 *
 *  Author:           Sudhir Ray
 *  Email:            raysudhir30@gmail.com
 *  Label:            P01
 *  Title:            Database Indexes
 *  Course:           3013 Algorithm
 *  Semester:         Spring 2023
 *
 *  Description:
 *             This program takes all the data from the json file and adds the
 *data to a binary search tree sorted according to eight different fields. The
 *program also allows the user to search for information as they please with
 *different fields.
 *
 *
 *  Usage:
 *       N/A
 *
 *  Files:
 *       main.cpp            : driver program
 *       json.hpp            : json library
 *       actual_data.json    : file with the data
 *****************************************************************************/

#include "json.hpp"
#include <algorithm>
#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;
using json = nlohmann::json;

/**
 * lower
 *
 * Description:
 *      The function converts the given string into lower case.
 *
 * Params:
 *      string     :  the string to be converted into lower string
 *
 * Returns:
 *      string     : string in lower case
 */
string lower(string searchWord) {
  transform(searchWord.begin(), searchWord.end(), searchWord.begin(),
            ::tolower);
  return searchWord;
}

/**
 * Employee
 *
 * Description:
 *      This struct provides the structure for employee data.
 *
 * Public Methods:
 *                         N/A
 *
 * Private Methods:
 *                          N/A
 *
 * Usage:
 *      Provides a structure for employee data.
 *
 */

struct Employee {
  int id;
  string first_name;
  string last_name;
  string email;
  string address;
  string city;
  string state;
  double latitude;
  double longitude;
  string car;
  string car_model;
  string car_color;
  string favorite_movie;
  string pet;
  string job_title;
  string phone_number;
  vector<string> stocks;
};

/**
 * ListNode
 *
 * Description:
 *      This struct provides the structure for nodes in the linked list.
 *
 * Public Methods:
 *                         N/A
 *
 * Private Methods:
 *                          N/A
 *
 * Usage:
 *      Provides a structure for linked list.
 *
 */

struct ListNode {
  Employee data;
  struct ListNode *next;
};

/**
 * insert_LinkedList
 *
 * Description:
 *      The function adds new node in the linked list.
 *
 * Params:
 *      ListNode     :
 *      Employee     :  object of the struct Employee
 * Returns:
 *      N/A
 */

void insert_LinkedList(ListNode **root, Employee employee) {
  ListNode *new_node = new ListNode();
  new_node->data = employee;
  new_node->next = NULL;
  if (*root == NULL) {
    *root = new_node;
  } else {
    ListNode *lastnode = *root;
    while (lastnode->next != NULL) {
      lastnode = lastnode->next;
    }
    lastnode->next = new_node;
  }
}

/**
 * searchList
 *
 * Description:
 *      The function searches for a node in the linked list with string key.
 *
 * Params:
 *      ListNode     :  node to search
 *      string       :  key to search the node with
 * Returns:
 *      ListNode     : node being searched for
 */

ListNode *searchList(ListNode *node, string searchKey) {
  int comp = 0;
  if (node == NULL) {
    return node;
  }
  while (node != NULL) {
    comp++;
    if (lower(node->data.first_name).find(searchKey) != string::npos ||
        lower(node->data.last_name).find(searchKey) != string::npos ||
        lower(node->data.email).find(searchKey) != string::npos ||
        lower(node->data.address).find(searchKey) != string::npos ||
        lower(node->data.city).find(searchKey) != string::npos ||
        lower(node->data.state).find(searchKey) != string::npos ||
        lower(node->data.car).find(searchKey) != string::npos ||
        lower(node->data.phone_number).find(searchKey) != string::npos) {
      cout << "Compared " << comp << " Nodes." << endl;
      return node;
    }
    node = node->next;
  }
  cout << "Compared " << comp << " Nodes." << endl;
  return node;
}
/**
 * searchList
 *
 * Description:
 *      Overloaded searchList. The function searches for a node in the linked
 * list with integer key.
 *
 * Params:
 *      ListNode     :  node to search
 *      int          :  key to search the node with
 * Returns:
 *      ListNode     : node being searched for
 */

ListNode *searchList(ListNode *node, int search_key) {
  int comp = 0;
  if (node == NULL) {
    return node;
  }
  while (node != NULL) {
    comp++;
    if (node->data.id == search_key) {
      cout << "Compared " << comp << " Nodes." << endl;
      return node;
    }
    node = node->next;
  }
  cout << "Compared " << comp << " Nodes." << endl;
  return node;
}

/**
 * searchList
 *
 * Description:
 *      Overloaded searchList. The function searches for a node in the linked
 * list with longitude and latitude.
 * Params:
 *      ListNode     :  node to search
 *      int          :  latitude to search the node with
 *      int          :  lngitude to search the node with
 * Returns:
 *      ListNode     : node being searched for
 */

ListNode *searchList(ListNode *node, double latitude, double longitude) {
  int comp = 0;
  if (node == NULL) {
    return node;
  }
  while (node != NULL) {
    comp++;
    if (node->data.latitude == latitude && node->data.longitude == longitude) {
      cout << "Compared " << comp << " Nodes." << endl;
      return node;
    }
    node = node->next;
  }
  cout << "Compared " << comp << " Nodes." << endl;
  return node;
}

/**
 * BST
 *
 * Description:
 *      This struct provides the structure for binary search tree.
 *
 * Public Methods:
 *                         N/A
 *
 * Private Methods:
 *                          N/A
 *
 * Usage:
 *      Provides a structure for binary search tree.
 *
 */
struct BST {
  string key;
  Employee employee;
  BST *left;
  BST *right;
};

/**
 * insert
 *
 * Description:
 *      The function adds new node in the binary search tree.
 *
 * Params:
 *      BST          :  root of the binary search tree.
 *      Employee     :  data of the employee to add in the node.
 *      string       :  key to insert the data with
 * Returns:
 *      N/A
 */

void insert(BST *&root, Employee record, string key) {
  if (root == NULL) {
    root = new BST;
    root->key = key;
    root->employee = record;
    root->left = NULL;
    root->right = NULL;
  } else {
    if (key < root->key) {
      insert(root->left, record, key);
    } else {
      insert(root->right, record, key);
    }
  }
}

/**
 * insert
 *
 * Description:
 *      Overloaded insert. The function adds new node in the binary search tree
 * with integer key.
 *
 * Params:
 *      BST          :  root of the binary search tree.
 *      Employee     :  data of the employee to add in the node.
 *      int          :  integer key to insert the data with
 * Returns:
 *      N/A
 */

void insert(BST *&root, Employee record, int key) {
  if (root == NULL) {
    root = new BST;
    root->key = to_string(key);
    root->employee = record;
    root->left = NULL;
    root->right = NULL;
  } else {
    if (key < stoi(root->key)) {
      insert(root->left, record, key);
    } else {
      insert(root->right, record, key);
    }
  }
}

/**
 * insert
 *
 * Description:
 *      Overloaded insert. The function adds new node in the binary search tree
 * with the combination of longitude and latitude as the key.
 *
 * Params:
 *      BST          :  root of the binary search tree.
 *      Employee     :  data of the employee to add in the node.
 *      double       :  combination of longitude and latitude as a key to insert
 * the data with
 * Returns:
 *   N/A
 */

void insert(BST *&root, Employee record, double key) {
  if (root == NULL) {
    root = new BST;
    root->key = to_string(key);
    root->employee = record;
    root->left = NULL;
    root->right = NULL;
  } else {
    if (record.latitude + record.longitude < stod(root->key)) {
      insert(root->left, record, key);
    } else {
      insert(root->right, record, key);
    }
  }
}

/**
 * *search
 *
 * Description:
 *       The function searches for a node in the binary
 * search tree with integer key.
 *
 * Params:
 *      BST          :  root of the BST
 *      int          :  key to search the node with
 * Returns:
 *      BST          : node with the key
 */

BST *search(BST *root, int searchKey) {
  static int count = 0;
  count++;
  if (!root) {
    cout << endl;
    cout << "Node count:" << count << endl;
  } else if (root->employee.id == searchKey) {
    cout << endl;
    cout << "Node count:" << count << endl;
    return root;
  } else if (searchKey < root->employee.id) {
    return search(root->left, searchKey);
  } else {
    return search(root->right, searchKey);
  }
}

/**
 * *search
 *
 * Description:
 *       Overloaded *search function. The function searches for a node in the
 * binary search tree with integer key.
 *
 * Params:
 *      BST          :  root of the BST
 *      string       :  string key to search the node with
 * Returns:
 *      BST          : node with the key
 */

BST *search(BST *root, string searchKey) {
  static int count = 0;
  count++;
  if (root == NULL || root->key.find(searchKey) != string::npos) {
    cout << endl;
    cout << "Node count:" << count << endl;
    return root;

  } else if (searchKey < root->key) {
    return search(root->left, searchKey);
  } else {
    return search(root->right, searchKey);
  }
}

/**
 * *search
 *
 * Description:
 *       Overloaded *search function. The function searches for a node in the
 * binary search tree with longitude and latitude as key.
 *
 * Params:
 *      BST          :  root of the BST
 *      double       :  latitude
 *      double       :  longitude
 * Returns:
 *      BST          : node with the key combination of longitude and latitude
 */

BST *search(BST *root, double latitude, double longitude) {
  static int count = 0;
  count++;
  if (root == NULL || root->employee.latitude + root->employee.longitude ==
                          (latitude + longitude)) {
    cout << endl;
    cout << "Node count:" << count << endl;
    return root;

  } else if ((latitude + longitude) <
             (root->employee.latitude + root->employee.longitude)) {
    return search(root->left, latitude, longitude);
  } else {
    return search(root->right, latitude, longitude);
  }
}
int option;       // option choice for user to search data with
string searchKey; // searchkey for the functions

/**
 * choice
 *
 * Description:
 *      The function provides the user with all the fields that they can search
 * the employee data with.
 * Params: N/A
 *
 * Returns:
 *      int     :  integer with the coice information
 */
int choice() {
  cout << "Select the field you want to search data on:\n"
       << "0.Id\n"
       << "1.First Name\n"
       << "2.Last Name\n"
       << "3.Address\n"
       << "4.Email\n"
       << "5.City\n"
       << "6.State\n"
       << "7.Car\n"
       << "8.Phone number\n"
       << "9.GPS (Longitude and Latitude)\n"
       << "10.Exit\n";
  cout << "Enter Your Choice:";
  cin >> option;
  cin.ignore();

  return option;
}

int main() {

  BST *bstId = NULL;
  BST *bstFname = NULL;
  BST *bstLname = NULL;
  BST *bstAddress = NULL;
  BST *bstEmail = NULL;
  BST *bstCity = NULL;
  BST *bstState = NULL;
  BST *bstCar = NULL;
  BST *bstPhone_number = NULL;
  BST *bstGps = NULL;
  ListNode *linkedlist = NULL;

  // data from the json file
  ifstream file("actual_data.json");
  string str;
  vector<Employee> Employees; // vector of the Employee
  json j;
  file >> j;

  for (size_t i = 0; i < j.size(); i++) {
    vector<string> stocks; // Vector for the stocks

    for (const auto &elements : j[i]["stocks"]) {
      stocks.push_back(elements.get<string>());
    }

    Employee employee = {j[i]["id"],
                         j[i]["first_name"],
                         j[i]["last_name"],
                         j[i]["email"],
                         j[i]["address"],
                         j[i]["city"],
                         j[i]["state"],
                         j[i]["latitude"],
                         j[i]["longitude"],
                         j[i]["car"],
                         j[i]["car_model"],
                         j[i]["car_color"],
                         j[i]["favorite_movie"],
                         j[i]["pet"],
                         j[i]["job_title"],
                         j[i]["phone_number"],
                         stocks};
    Employees.push_back(employee);
  }
  // shuffling the data
  shuffle(Employees.begin(), Employees.end(), random_device());

  // inserting data into BST
  for (auto employee : Employees) {
    insert(bstId, employee, employee.id);
    insert(bstFname, employee, lower(employee.first_name));
    insert(bstLname, employee, lower(employee.last_name));
    insert(bstAddress, employee, lower(employee.address));
    insert(bstEmail, employee, lower(employee.email));
    insert(bstCity, employee, lower(employee.city));
    insert(bstState, employee, lower(employee.state));
    insert(bstCar, employee, lower(employee.car));
    insert(bstPhone_number, employee, lower(employee.phone_number));
    insert(bstGps, employee, (employee.latitude + employee.longitude));
    insert_LinkedList(&linkedlist, employee);
  }

  int optionNum;
  int idSearchData;
  optionNum = choice();

  // timer variables

  auto t_start = std::chrono::high_resolution_clock::now();
  auto t_end = std::chrono::high_resolution_clock::now();
  auto t_end2 = std::chrono::high_resolution_clock::now();
  double time;

  BST *e;
  ListNode *e2;
  double latitude;
  double longitude;

  while (optionNum != 10) {
    if (optionNum == 9) {
      cout << "Enter latitude:";
      cin >> latitude;
      cout << "Enter longitude:";
      cin >> longitude;
      cin.ignore();
    } else {
      cout << "Enter string to be search Data:";
      getline(cin, searchKey);
    }
    if (optionNum == 0) {
      idSearchData = stoi(searchKey);
    }
    searchKey = lower(searchKey);
    t_start = std::chrono::high_resolution_clock::now();
    if (optionNum == 0) {
      e = search(bstId, idSearchData);
      } else if (optionNum == 1) {
      e = search(bstFname, searchKey);
      } else if (optionNum == 2) {
      e = search(bstLname, searchKey);
      } else if (optionNum == 3) {
      e = search(bstAddress, searchKey);
      } else if (optionNum == 4) {
      e = search(bstEmail, searchKey);
      } else if (optionNum == 5) {
      e = search(bstCity, searchKey);
      } else if (optionNum == 6) {
      e = search(bstState, searchKey);
      } else if (optionNum == 7) {
      e = search(bstCar, searchKey);
      } else if (optionNum == 8) {
      e = search(bstPhone_number, searchKey);
      } else if (optionNum == 9) {
      e = search(bstGps, latitude, longitude);
      }
    t_end = std::chrono::high_resolution_clock::now();
    if (optionNum != 9) {
      e2 = searchList(linkedlist, searchKey);
    } else if (optionNum == 0) {
      e2 = searchList(linkedlist, stoi(searchKey));
    } else {
      e2 = searchList(linkedlist, latitude, longitude);
    }
    t_end2 = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration<double, std::micro>(t_end - t_start).count();
    cout << "Completed search in BST in " << time << " micro sec" << endl;
    time = std::chrono::duration<double, std::micro>(t_end2 - t_end).count();
    cout << "Completed search in Linked List in " << time << " micro sec"
         << endl;

    if (e != NULL) {
      cout << "Found String " + searchKey + " in " << e->employee.first_name
           << endl;
      string stocks;
      for (vector<string>::const_iterator i = e->employee.stocks.begin();
           i != e->employee.stocks.end(); ++i)
        stocks += *i + ", ";
      // Printing the information the user is looking for
      cout << "Details:" << endl;
      cout << "id : " << e->employee.id
           << "\nfirst_name : " << e->employee.first_name
           << "\nlast_name : " << e->employee.last_name
           << "\nemail: " << e->employee.email
           << "\naddress: " << e->employee.address
           << "\ncity: " << e->employee.city << "\nstate: " << e->employee.state
           << "\nlatitude: " << e->employee.latitude
           << "\nlongitude: " << e->employee.longitude
           << "\ncar: " << e->employee.car
           << "\ncar_model: " << e->employee.car_model
           << "\ncar_color: " << e->employee.car_color
           << "\nfavorite_movie: " << e->employee.favorite_movie
           << "\npet: " << e->employee.pet
           << "\njob_title: " << e->employee.job_title
           << "\nphone_number: " << e->employee.phone_number
           << "\nstocks: " << stocks << endl;
    } else {
      cout << "Not Found" << endl; // if the information doesn't exist.
    }
    cout << endl;
    optionNum = choice();
  }
  return 0;
}
