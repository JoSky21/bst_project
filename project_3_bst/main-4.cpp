/*
	Author: Jonathan Harjono
	NetID: jh4482
	Compiler used: Visual Studio 2019
	Program description: This program allows the user to create a binary search tree
						that supports insert, delete, search, and saves the postorder traversal to a file.
*/


#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include "bst.h"

using std::string;

struct WrongInput : public std::exception {
	const char* what() const throw() {
		return "Wrong input. Try again.";
	}
};

int main() {
	string choice;
	std::cout << "Welcome to the BST program." << std::endl;
	BST* tree1 = new BST();
	std::cout << "Here is the menu for the program." << std::endl;
	do {
		std::cout << std::endl;
		std::cout << "1. Create a BST." << std::endl;
		std::cout << "2. Insert a string to BST." << std::endl;
		std::cout << "3. Search a string from BST." << std::endl;
		std::cout << "4. Remove a string from BST." << std::endl;
		std::cout << "5. Output the in-order traversal." << std::endl;
		std::cout << "6. Output the pre-order traversal." << std::endl;
		std::cout << "7. Output the post-order traversal." << std::endl;
		std::cout << "8. Save the post-order traversal to a file." << std::endl;
		std::cout << "9. Delete the entire tree." << std::endl;
		std::cout << "0. Exit the program." << std::endl;

		std::cin >> choice;
		if (choice == "1") {
			delete tree1;
			tree1 = new BST();
			std::cout << "BST has been created." << std::endl;
		}
		if (choice == "2") {
			string input; 
			std::cout << "Please input the string." << std::endl;
			std::cin >> input;
			
			tree1->insert(input);
		}
		if (choice == "3") {
			string search;
			std::cout << "Please insert string to search." << std::endl;
			std::cin >> search;
			string result; 
			result = tree1->search(search);
			std::cout << result << std::endl;
		}
		if (choice == "4") {
			string delete_data;
			std::cout << "Please insert string to delete." << std::endl;
			std::cin >> delete_data;
			tree1->deleteString(delete_data);
		}
		if (choice == "5") {
			tree1->inOrderOut(std::cout);
		}
		if (choice == "6") {
			tree1->preOrderOut(std::cout);
		}
		if (choice == "7") {
			tree1->postOrderOut(std::cout);
		}
		if (choice == "8") {
			string filename;
			std::cout << "Please enter the file name you want to store the post order in: " << std::endl;
			std::cout << "Please make it more than 5 characters long and don't forget the .txt file extension." << std::endl;
			std::cin >> filename;
			
			string check = "";
			for (int i = filename.size()-1; i > filename.size() - 5; --i) {
				check += filename[i];
			}
			if (check.size() < 4) {
				std::cout << "File name too small." << std::endl;
				std::cout << "Go back to the menu and do it again." << std::endl;
				std::cout << std::endl;
				;
			}
			if (check != "txt.") {
				std::cout << "You forgot the .txt file extension." << std::endl;
				std::cout << "Go back to the menu and do it again." << std::endl;
				std::cout << std::endl;
				;
			}
			else {
				std::ofstream ofs;
				ofs.open(filename, std::ofstream::out | std::ofstream::app);
				tree1->postOrderOut(ofs);
				ofs.close();
			}
		}
		if (choice == "9") {
			string option;
			std::cout << "You will delete the entire tree." << std::endl;
			std::cout << "Are you sure? You cannot undo this action. (y/n)" << std::endl;
			std::cin >> option;
			if (option == "y") {
				tree1->lumberjack();
			}
			else if (option == "n") {
				std::cout << "You have selected no." << std::endl;
				std::cout << "Returning to menu." << std::endl;
				std::cout << std::endl;
			}
		}
	} while (choice != "0");

	std::cout << "Thank you for using this program." << std::endl;

	return 0;
}