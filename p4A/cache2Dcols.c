////////////////////////////////////////////////////////////////////////////////
// Main File:        cache2Dcols.c
// This File:        cache2Dcols.c
// Other Files:      (name of all other files if any)
// Semester:         CS 354 Lecture 01 Fall 2022
// Instructor:       deppeler
// 
// Author:           Wenpei Shao
// Email:            wshao33@wisc.edu
// CS Login:         wenpei
//
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//
// Persons:          Identify persons by name, relationship to you, and email.
//                   Describe in detail the the ideas and help they provided.
//
// Online sources:   avoid web searches to solve your problems, but if you do
//                   search, be sure to include Web URLs and description of 
//                   of any information you find.
//////////////////////////// 80 columns wide ///////////////////////////////////
//
int arr2D[3000][500];//array with 3000 rows and 500 cols;
int main(){
	for (int i = 0; i < 500; i++){
		for (int j = 0; j < 3000; j++){
			arr2D[j][i] = i + j;
		}
	}
}
