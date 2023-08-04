#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
 
	
class BST{
	//std::string data;
    string data;
    BST *left, *right;
 
public:
    // Default constructor.
    BST();
 
    // Parameterized constructor.
    BST(string);
 
    // Insert function.
    BST* Insert(BST*, string);
    
    BST* remove(string, BST*);
    
    BST* findMin(BST* );
 
    // Inorder traversal.
    void Inorder(BST*);
    
    bool search(BST*, string);
};
 
// Default Constructor definition.
BST ::BST()
    : data("")
    , left(NULL)
    , right(NULL)
{
}
 
// Parameterized Constructor definition.
BST ::BST(string value)
{
    data = value;
    left = right = NULL;
}
 
// Insert function definition.
BST* BST ::Insert(BST* root, string value){
    if (!root){
        return new BST(value);
    }
    if (value> root->data){
        root->right = Insert(root->right, value);
    }else{
        root->left = Insert(root->left, value);
    }
    return root;
}
	BST* BST ::remove(string value, BST* b){
    	BST* temp;
		if(b == NULL)
			return NULL;
    	else if(value < b->data)
    		b->left = remove(value, b->left);
        else if(value > b->data)
            b->right = remove(value, b->right);
        else if(b->left && b->right){
            temp = findMin(b->right);
            b->data = temp->data;
            b->right = remove(b->data, b->right);
        }
        else{
            temp = b;
            if(b->left == NULL)
                b = b->right;
            else if(b->right == NULL)
                b = b->left;
            delete temp;
        }
        return b;
    }
    
	BST* BST ::findMin(BST* b){
        if(b == NULL)
            return NULL;
        else if(b->left == NULL)
            return b;
        else
            return findMin(b->left);
	}
 
// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST* root){
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

// search in BST
bool BST ::search(BST* root, string value){
	//*
	if(!root)
		return false;
	else if(root->data == value)
		return true;
    else if(root->data > value)
		return search(root->left, value);
	else if(root->data < value)
		return search(root->right, value);
	else
		return false;
	//*/
}
 
// Driver code
int main(){
	
	ifstream read ("records.txt");
	string line;
    BST b,*root = NULL;
    root = b.Insert(root, "Amiri");
	bool continu=true;
	//*
	b.Insert(root, "sajad");
	b.Insert(root, "hasan");
	b.Insert(root, "behdad");
	b.Insert(root, "mostafa");
	b.Insert(root, "hamed");
	//*/
	while(continu){
		int n;
		cout<<"1_make tree	2_change tree	3_correct your sentences	4_alphabetical sort 	5_Exit"<<endl;
		string phrase;
		cin>> n;
		
		switch(n){
			case 1:
				getline(read,line);
    			root = b.Insert(root, line );
    			while(getline(read,line)){
					b.Insert(root, line);
				}
				break;
			case 2:
				cout<<"1_Insert 	2_Remove 	3_Change"<<endl;
				cin>>n;
				switch(n){
					case 1:
						cout<<"what word would you like to add?"<<endl;
						cin>>phrase;
						b.Insert(root, phrase);
					break;
					case 2:
						cout<<"what word would you like to Remove?"<<endl;
						cin>>phrase;
						b.remove(phrase, root);
					break;
					case 3:
						cout<<"what word would you like to Change?"<<endl;
						cin>>phrase;
						b.remove(phrase, root);
						cout<<"change to what?"<<endl;
						cin>>phrase;
						b.Insert(root, phrase);
					break;
				}
				break;
				
			case 3:
				cout<<"Insert your phrase(for stop enter \";\"):"<<endl;
				while(true){
					cin>>phrase;
					if(phrase!=";" && !b.search(root, phrase)){
						cout<<"this word is not correct"<<endl;
					}else if(phrase == ";"){
						break;
					}else{
						cout<<"this word is correct "<<endl;
					}
				}
				//words=new string[wordCounter(phrase)];
				//words=wordExtracter(phrase);
				/*
				for(int i=0; i<10; i++){
					if(!b.search(root, words[i])){
						cout<<"this word is not correct: "<< words[i]<<endl;
					}	
				}
				//*/
				break;
			case 4:
    			b.Inorder(root);
    			break;
    		case 5:
    			continu=false;
    			break;
			default:
				break;
		}
		
	}
    return 0;
}











