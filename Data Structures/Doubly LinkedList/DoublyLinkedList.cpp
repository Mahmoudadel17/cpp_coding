#include <iostream>

using namespace std;


template<class t>
	struct Node{
		t data;
		Node* next;
		Node* prev;

		Node(){
			next = nullptr;
			prev = nullptr;
		}
	};

template<class t>
class DoublyLinkedList{
private:
	Node<t>* head = nullptr,*tail = nullptr;
public:
    
    DoublyLinkedList<t>& operator = (DoublyLinkedList& rhs) // * - &
    {
        if (this == &rhs){return *this;}
        iterator it = rhs.begin();
        while (it != rhs.end())
        {
            this->push_back(*it);
            ++it;
        }
        this->push_back(*it);
        return *this;
    
    }
    class iterator
    {
        friend class DoublyLinkedList;
    private:
        /* data */
        Node<t>* currentNode;
    public:
        iterator()
        {
            currentNode = nullptr;
        }
        iterator(Node<t>* current_Node)
        {
            currentNode = current_Node;

        }
        void operator++()
        {
            if (currentNode->next == NULL)
            {
                throw("ERROR,currently pointing after the last element");
            }
            currentNode = currentNode->next;
        }
        void operator--()
        {
            if (currentNode->prev == NULL)
            {
                throw("ERROR,currently pointing to the first element of the list.t");
            }
            currentNode = currentNode->prev;
            
        }
        t& operator*() const
        {
            return currentNode->data;
        }
        bool operator==(const iterator &it)
        {
            return  currentNode == it.currentNode;
        }
        bool operator!=(const iterator &it)
        {
            return  currentNode != it.currentNode;
        }  
    };
    iterator begin() const
    {
        return iterator(head);
    }
    iterator end() const
    {
        return iterator(tail);
    }
	void push_back(t val){
		Node<t>* newNode = new Node<t>;
		newNode->data = val;
		if (head == nullptr){
			head = newNode;
            tail = newNode;
		}
		else{
			Node<t>* temp = head;
			while (temp->next != nullptr){
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->prev = temp;
            tail = newNode;
		}
	}

	void push_at_pos(t val, int pos){
		Node<t>* newNode = new Node<t>;
		newNode->data = val;
		if (head == nullptr){//
			head = newNode;
			return;
		}//
		if (pos == 0){
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
			return;
		}

		Node<t>* temp = head;
		for (int i = 0; i < pos && temp != nullptr; i++){
			temp = temp->next;
		}
        if (temp == tail)
        {
            tail = newNode;
        }
		if (temp == nullptr){
			push_back(val);
			return;
		}

		newNode->prev = temp->prev;
		temp->prev->next = newNode;
		temp->prev = newNode;
		newNode->next = temp;

          
	}

	void remove(t val){
        if (val == tail->data)
        {
            tail = tail->prev;
        }
        
		if (head == nullptr)
			return;

		Node<t>* temp;
		temp = head;

		if (temp->data == val){
			head = temp->next;
			if (head != nullptr)
				head->prev = nullptr;
			delete temp;
			return;
		}

		while (temp != nullptr && temp->data != val){
			temp = temp->next;
		}

		if (temp == nullptr){
			return;
		}
		else{
			temp->prev->next = temp->next;
			if (temp->next != nullptr)
				temp->next->prev = temp->prev;
			delete temp;
		}
	}

	void remove_at_pos(int pos){
		int sizee=0;
        Node<t>*tm=head;
        while (tm!=0)
        {
        sizee++;
        tm = tm->next;
        }
        if (pos = sizee-1)
        {
            tail = tail->prev;
        }
        delete tm;
		if (head == nullptr)
			return;

		Node<t>* temp = head;
		if (pos == 0){
			head = temp->next;
			if (head)
				head->prev = nullptr;
			delete temp;
			return;
		}

		for (int i = 0; i < pos && temp != nullptr; i++)
			temp = temp->next;

		if (temp == nullptr)
			return;

		temp->prev->next = temp->next;
		if (temp->next)
			temp->next->prev = temp->prev;
		delete temp;

	}

	void display(){
		Node<t>* temp = head;
		while (temp != nullptr){
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
        delete temp;

	}

	void reverse_display(){
		Node<t>* temp = head;
		while (temp->next != nullptr){
			temp = temp->next;
		}
		//---------------------------
		while (temp != nullptr){
			cout << temp->data << " ";
			temp = temp->prev;
		}
		cout <<endl;
        delete temp;

	}
    int size()
    {
        int sizee=0;
        Node<t>*temp=head;
        while (temp!=0)
        {
        sizee++;
        temp = temp->next;
        }
        return sizee;
    }

	~DoublyLinkedList(){
		Node<t>* temp = head;
		while (head != nullptr){
			head = head->next;
			delete temp;
			temp = head;
		}
	}

iterator erase(iterator pos) 
{   if (head == pos.currentNode)
    {
	head = pos.currentNode->next;
	pos.currentNode->next = pos.currentNode->next->next;
	delete pos.currentNode;
	 return pos;
    }
	--pos;
    Node<t> *temp = pos.currentNode->next;
    pos.currentNode->next = pos.currentNode->next->next;
    if (temp == tail) tail = pos.currentNode;
    delete temp;
    return pos;
}


};


int main()
{
    try
	{
		DoublyLinkedList<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        list.push_back(4);
        list.push_back(5);
        list.display();
		list.push_at_pos(6,6);
		list.display();
		list.remove_at_pos(1);
		list.display();
		cout<<"size is: "<<list.size()<<endl;
		list.remove(2);
		list.display();
        DoublyLinkedList<int>::iterator it = list.begin();
		++it;
		cout<<*it<<endl;
		++it;
		cout<<*it<<endl;
		++it;
		cout<<*it<<endl;
		//++it; // error, pointing after the last element
		//cout<<*it<<endl;
		--it;
		cout<<*it<<endl;
		--it;
		cout<<*it<<endl;
		--it;
		cout<<*it<<endl;
		//--it;   // error, pointing to the first element
		//cout<<*it<<endl;
        list.erase(it);
        list.display();
		
		DoublyLinkedList<int> list2;
		list2 = list;
		list2.display();
		

        
	}
	catch(const char* e)
	{
		cout<< e<< '\n';
	}
	


}