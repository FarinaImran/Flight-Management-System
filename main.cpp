#include<iostream>
#include<fstream>
#include<string>
using namespace std;
template<class t>
class Node {
public:
	t name;
	bool visited = 0;
	Node<t>* next = NULL;
};

template<class t>
class Nodee {
public:
	Node<t>* r;
	Nodee<t>* next;
};
template<class t>
class queue {
public:
	Nodee<t>* head;
	void push(Node<t>* node)
	{
		if (head == NULL)
		{
			head = new Nodee<t>();
			head->r = node;
			head->next = NULL;
		}
		else
		{
			Nodee<t>* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			Nodee<t>* re = new Nodee<t>();
			re->r = node;
			re->next = NULL;
			temp->next = re;
		}
	}
	Node<t>* pop()
	{
		if (head->next == NULL)
		{
			Nodee<t>* re = new Nodee<t>();
			re->r = head->r;
			re->next = NULL;
			head = NULL;
			return re->r;
		}
		else
		{
			Nodee<t>* re = new Nodee<t>();
			re->r = head->r;
			re->next = NULL;
			head = head->next;
			return re->r;
		}
	}
	int isempty()
	{
		if (head == NULL)
			return 1;
		else
			return 0;
	}
};
template<class t>
class LinkedList {
public:
	Node<t>* head;
	LinkedList()
	{
		head = NULL;
	}
};
template<class t>
class graph {
public:
	LinkedList<t>* arraryofc;
	LinkedList<int>* arrayofdis;
	int index = 0;
	graph(int no_of_citi)
	{
		arraryofc = new LinkedList<t>[no_of_citi];
		arrayofdis = new LinkedList<int>[no_of_citi];
	}
	void addNode(t city)
	{
		bool founded = 0;
		for (int i = 0; i < index; i++)
		{
			if (arraryofc[i].head->name == city)
			{
				founded = 1;
				break;
			}
		}
		if (founded == 0)
		{
			Node<t>* h = arraryofc[index].head;
			if (h == NULL)
			{
				arraryofc[index].head = new Node<t>();
				arraryofc[index].head->name = city;
				arraryofc[index].head->next = NULL;
				arrayofdis[index].head = new Node<int>();
				arrayofdis[index].head->name = 0;
				arrayofdis[index].head->next = NULL;
				index++;
			}
		}
	}
	void addedge(string from, string dest, int dst)
	{
		for (int i = 0; i < index; i++)
		{
			if (arraryofc[i].head->name == from)
			{
				Node<t>* h = arraryofc[i].head;
				if (h == NULL)
				{
					arraryofc[i].head = new Node<t>();
					arraryofc[i].head->name = dest;
					arraryofc[i].head->next = NULL;
					arrayofdis[i].head = new Node<int>();
					arrayofdis[i].head->name = dst;
					arrayofdis[i].head->next = NULL;
				}
				else
				{
					Node<t>* temp = arraryofc[i].head;
					Node<int>* temp2 = arrayofdis[i].head;
					while (temp->next != NULL)
					{
						temp2 = temp2->next;
						temp = temp->next;
					}
					Node<t>* recieved = new Node<t>();
					recieved->name = dest;
					recieved->next = NULL;
					temp->next = recieved;

					Node<int>* recievedd = new Node<int>();
					recievedd->name = dst;
					recievedd->next = NULL;
					temp2->next = recievedd;
				}
				break;
			}
		}
	}
	void disp()
	{
		for (int i = 0; i < index; i++)
		{
			Node<t>* temp = arraryofc[i].head;
			Node<int>* tempdst = arrayofdis[i].head;
			tempdst = tempdst->next;
			while (temp->next != NULL)
			{
				cout << temp->name << "   ";
				cout << tempdst->name << "->";
				temp = temp->next;
				tempdst = tempdst->next;
			}
			cout << temp->name << "";
			cout << endl;

		}
	}
	int vistedor(t v)
	{
		for (int i = 0; i < index; i++)
		{
			if (arraryofc[i].head->name == v)
			{
				if (arraryofc[i].head->visited == 1)return 1;
				else return false;
			}
		}
	}
	int invistedor(t v)
	{
		for (int i = 0; i < index; i++)
		{
			if (arraryofc[i].head->name == v)
			{
				return i;
			}
		}
	}
	void dfs(Node<t>* ri)
	{
		int fi = 0;
		for (int i = 0; i < index; i++)
		{
			if (arraryofc[i].head->name == ri->name)
			{
				arraryofc[i].head->visited = 1;
				fi = i;
				break;
			}
		}
		cout << ri->name << " ";
		Node<t>* temp = arraryofc[fi].head;
		while (temp != NULL)
		{
			if (vistedor(temp->name) == 0)
			{
				dfs(temp);
			}
			temp = temp->next;
		}
	}
	void dfsss()
	{
		for (int i = 0; i < index; i++)
		{
			arraryofc[i].head->visited = 0;
		}

		for (int i = 0; i < index; i++)
		{
			if (arraryofc[i].head->visited == 0)
				dfs(arraryofc[i].head);
		}
	}



	void bfs(Node<t>* ri)
	{
		int fi = 0;
		for (int i = 0; i < index; i++)
		{
			arraryofc[i].head->visited = 0;
		}
		for (int i = 0; i < index; i++)
		{
			if (arraryofc[i].head->name == ri->name)
			{
				arraryofc[i].head->visited = 1;
				fi = i;
				break;
			}
		}

		queue<t>* q = new queue<t>();
		q->push(arraryofc[fi].head);


		while (q->isempty() == 0)
		{
			Node<t>* t1 = q->pop();
			cout << t1->name << " ";
			Node<t>* temp = t1;
			while (temp != NULL)
			{
				if (vistedor(temp->name) == 0)
				{
					arraryofc[invistedor(temp->name)].head->visited = 1;
					q->push(arraryofc[invistedor(temp->name)].head);
				}
				temp = temp->next;
			}
		}
	}

	void Dijikstra(string sou, string dsi)
	{

		int* parentnode = new int[index];
		int* distance = new int[index] {9999};
		bool* visited = new bool[index] {0};

		Node<t>* tem = arraryofc[invistedor(sou)].head;
		arraryofc[invistedor(sou)].head = arraryofc[0].head;
		arraryofc[0].head = tem;
		distance[invistedor(sou)] = 0;

		int** adjmatrix = new int* [index];
		for (int i = 0; i < index; i++)
		{
			adjmatrix[i] = new int[index];
		}
		for (int i = 0; i < index; i++)
		{
			for (int j = 0; j < index; j++)
			{
				adjmatrix[i][j] = 0;
			}
		}
		for (int i = 0; i < index; i++)
		{
			string s = arraryofc[i].head->name;
			Node<t>* temp = arraryofc[i].head;
			Node<int>* temp1 = arrayofdis[i].head;
			adjmatrix[invistedor(temp->name)][invistedor(temp->name)] = 0;
			temp = temp->next;
			temp1 = temp1->next;
			while (temp != NULL)
			{
				string d = temp->name;
				adjmatrix[invistedor(s)][invistedor(d)] = temp1->name;
				temp = temp->next;
			}
		}
		for (int i = 0; i < index; i++)
		{
			distance[i] = 99999;
		}
		distance[0] = 0;
		int seconedin = -8;
		for (int i = 0; i < index; i++)
		{
			int min = INT_MAX;

			for (int ii = 0; ii < index; ii++)
			{
				if (visited[ii] == false && distance[ii] < min)
				{
					min = distance[ii]; seconedin = ii;
				}
			}

			visited[seconedin] = 1;

			for (int j = 0; j < index; j++)
			{
				if (visited[j] != 1 && adjmatrix[seconedin][j] != 0)
				{
					if ((distance[seconedin] + adjmatrix[seconedin][j]) < distance[j])
					{
						distance[j] = distance[seconedin] + adjmatrix[seconedin][j];
						parentnode[j] = seconedin;
					}
				}
			}
		}
		cout << "\n-----------------Shortest-----------------------" << endl;
		int iii = 18;
		cout << endl;
		cout << dsi << " <- ";
		iii = parentnode[invistedor(dsi)];
		while (iii != 0)
		{
			cout << arraryofc[iii].head->name << " <- ";
			iii = parentnode[iii];
		}
		cout << arraryofc[0].head->name;
		cout << endl;

	}
	void prims()
	{
		int* parentnode = new int[index];
		int* distance = new int[index] {9999};
		bool* visited = new bool[index] {0};

		int** adjmatrix = new int* [index];
		for (int i = 0; i < index; i++)
		{
			adjmatrix[i] = new int[index];
		}
		for (int i = 0; i < index; i++)
		{
			for (int j = 0; j < index; j++)
			{
				adjmatrix[i][j] = 0;
			}
		}
		for (int i = 0; i < index; i++)
		{
			string s = arraryofc[i].head->name;
			Node<t>* temp = arraryofc[i].head;
			Node<int>* temp1 = arrayofdis[i].head;
			adjmatrix[invistedor(temp->name)][invistedor(temp->name)] = 0;
			temp = temp->next;
			temp1 = temp1->next;
			while (temp != NULL)
			{
				string d = temp->name;
				adjmatrix[invistedor(s)][invistedor(d)] = temp1->name;
				temp = temp->next;
			}
		}
		for (int i = 0; i < index; i++)
		{
			distance[i] = 99999;
		}
		distance[0] = 0;
		int seconedin = -8;
		for (int i = 0; i < index; i++)
		{
			int min = INT_MAX;

			for (int ii = 0; ii < index; ii++)
			{
				if (visited[ii] == false && distance[ii] < min)
				{
					min = distance[ii]; seconedin = ii;
				}
			}

			visited[seconedin] = 1;

			for (int j = 0; j < index; j++)
			{
				if (visited[j] != 1 && adjmatrix[seconedin][j] != 0)
				{
					if (adjmatrix[seconedin][j] < distance[j])
					{
						distance[j] = distance[seconedin] + adjmatrix[seconedin][j];
						parentnode[j] = seconedin;
					}
				}
			}
		}
		cout << "Shortest" << endl;
		parentnode[0] = 0;
		for (int i = 0; i < index; i++)
		{
			if (parentnode[i] >= 0 && parentnode[i] < index)
				cout << arraryofc[parentnode[i]].head->name << "<-" << arraryofc[i].head->name << endl;
		}
	}
};
void bubble(int* array_o, int indx)
{

	int* array_of_di = new int[indx];
	for (int i = 0; i < indx; i++)
	{
		array_of_di[i] = array_o[i];
	}
	for (int i = 0; i < indx; i++)
	{
		for (int j = i + 1; j < indx; j++)
		{
			if (array_of_di[i] > array_of_di[j])
			{
				int temp = array_of_di[i];
				array_of_di[i] = array_of_di[j];
				array_of_di[j] = temp;
			}
		}
	}
	cout << "-----------------------------------After bubbles-------------------------------" << endl;
	
}
void selection(int* array_o, int indx)
{
	int* array_of_di = new int[indx];
	for (int i = 0; i < indx; i++)
	{
		array_of_di[i] = array_o[i];
	}
	for (int i = 0; i < indx; i++)
	{
		int j = i;
		while (j != 0 && array_of_di[j] < array_of_di[j - 1])
		{
			int temp = array_of_di[j];
			array_of_di[j] = array_of_di[j - 1];
			array_of_di[j - 1] = temp;
			j--;
		}
	}
	cout << "---------------------------------After Selection--------------------------------" << endl<<endl;
	
}
void Merge(int* a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
    int size = high - low + 1;
	int i, j, k;
	int* temp = new int[size];
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i - low];
	}
}

// A function to split array into two parts.
void MergeSort(int* a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid + 1, high);

		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
	
}
void showArray(int* a, int size)
{
	for (int i = 0; i < size; i++)
		cout << " " << a[i];
	cout << endl;
}
void arra()
{
	int* array = new int[520];
	int indx = 0;
	ifstream file2("C:\\Users\\Hp\\Desktop\\DSA\\flight_network_spicejet.csv");
	while (file2.good())
	{
		string temp1 = "";
		string temp2 = "";
		string temp3 = "";
		getline(file2, temp1, ',');
		getline(file2, temp2, ',');
		getline(file2, temp3, '\n');

		int no = 0;
		int pos = 1;
		int in = 0;
		while (temp3[in] != '\0')
			in++;
		for (int i = 0; i < in - 1; i++)
			pos *= 10;
		for (int i = 0; i < in; i++)
		{
			no += ((temp3[i] - 48) * pos); pos /= 10;
		}
		array[indx] = no;
		indx++;
	}
	bubble(array, indx);
	showArray(array, indx);
	selection(array, indx);
	showArray(array, indx);
	MergeSort(array, 0, indx - 1);
	cout << "--------------------------------After Merge sort-------------------------------" << endl << endl;
	showArray(array, indx);
}
int main()
{
	graph<string> gra(100);


	ifstream file("C:\\Users\\Hp\\Desktop\\DSA\\flight_network_spicejet.csv");
	while (file.good())
	{
		string temp = "";
		char temc;
		getline(file, temp, ',');
		gra.addNode(temp);
		getline(file, temp, ',');
		gra.addNode(temp);
		getline(file, temp, '\n');
	}
	file.close();

	ifstream file2("C:\\Users\\Hp\\Desktop\\DSA\\flight_network_spicejet.csv");
	while (file2.good())
	{
		string temp1 = "";
		string temp2 = "";
		string temp3 = "";
		getline(file2, temp1, ',');
		getline(file2, temp2, ',');
		getline(file2, temp3, '\n');

		int no = 0;
		int pos = 1;
		int in = 0;
		while (temp3[in] != '\0')
			in++;
		for (int i = 0; i < in - 1; i++)
			pos *= 10;
		for (int i = 0; i < in; i++)
		{
			no += ((temp3[i] - 48) * pos); pos /= 10;
		}
		gra.addedge(temp1, temp2, no);
	}

	while(true){
	cout<< "\n 1- BFS \n 2- DFS \n 3- Dikikstra \n 4- Prims \n 5- sorting \n Enter Choice: ";
	int choice;
	cin >> choice;
	switch(choice){
		case 1:
			cout << "------------------------------BFS--------------------------" << endl;
			gra.bfs(gra.arraryofc[0].head);
			cout << endl;
			break;
		case 2:
			cout << "\n----------------------------DFS--------------------------" <<endl<< endl;
			gra.dfsss();
			cout << endl;
			break;
		case 3:
			cout << "\n----------------------------Dijikstra--------------------------" << endl << endl;
			gra.Dijikstra("Ahmedabad", "Vijayawada");
			cout << endl;
			break;
		case 4:
			cout << "\n----------------------------Prims--------------------------" << endl << endl;
			gra.prims();
			cout << endl;
			break;
		case 5:
			arra();
			break;
		default: 
			cout << "invalid input";
	}
}

}
