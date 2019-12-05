#pragma once

template <class ItemType>
struct NodeType;


template <class ItemType>
class SortedType
{
public:
	SortedType();	// Class constructor
	~SortedType();   	// Class destructor
	void InsertItem(ItemType item);
	void PrintList();
	void SetCurrentPos();
	void MoveToNextItem();
	NodeType<ItemType>* GetCurrentPos();
	void RetrieveItem(ItemType& item, bool& found);
	void DeleteItem(ItemType& item);
	void MakeEmpty();
	bool IsEmpty() const;

private:
	NodeType<ItemType>* listData;
	int length;
	NodeType<ItemType>* currentPos;
};

template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType>* next;
};

template <class ItemType>
SortedType<ItemType>::SortedType()
{
	length = 0;
	listData = NULL;
}


template <class ItemType>
SortedType<ItemType>::~SortedType() {}


//method to empty the lists 
template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
{
	NodeType<ItemType>* tempPtr;

	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	listData = NULL;
}
//check if the list if empty and assign it to null
template <class ItemType>
bool SortedType<ItemType>::IsEmpty() const
{
	return (listData == NULL);
}
//set the current position to a variable called "listData"
template <class ItemType>
void SortedType<ItemType>::SetCurrentPos()
{
	currentPos = listData;
}
//return current position
template <class ItemType>
NodeType<ItemType>* SortedType<ItemType>::GetCurrentPos()
{
	return currentPos;
}
//method to print out the values in the list
template <class ItemType>
void SortedType<ItemType>::PrintList()
{
	NodeType<ItemType>*tempptr;

	tempptr = listData;

	while (tempptr != NULL)
	{
		if (tempptr->info == tempptr->info) {
			cout << " " << tempptr->info;
			tempptr = tempptr->next;

		}
	}
}

template <class ItemType>
void SortedType<ItemType>::MoveToNextItem()
{
	currentPos = currentPos->next;
}

//method to insert an item 
template <class ItemType>
void SortedType<ItemType>::InsertItem
(ItemType item)
{
	NodeType<ItemType>* newNode;
	NodeType<ItemType>* predLoc;
	NodeType<ItemType>* location;

	bool moreToSearch;

	location = listData;
	predLoc = NULL;
	moreToSearch = (location != NULL);
	// Find insertion point.
	while (moreToSearch)
	{
		if (location->info < item)
		{
			predLoc = location;
			location = location->next;
			moreToSearch = (location != NULL);
		}
		//to avoid showing duplicates
		else if (location->info == item) return;

		else
			moreToSearch = false;
	}

	// Prepare node for insertion
	newNode = new NodeType<ItemType>;
	newNode->info = item;
	// Insert node into list.
	if (predLoc == NULL)
		
	{
		newNode->next = listData;
		listData = newNode;
	}
	else
	{
		newNode->next = location;
		predLoc->next = newNode;
	}
	length++;
}

template <class ItemType>
void SortedType<ItemType>::RetrieveItem
(ItemType& item, bool& found)
{
	bool moreToSearch;
	NodeType<ItemType>* location;

	location = listData;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (location->info < item)
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
		else if (item == location->info)
		{
			found = true;
			item = location->info;
		}
		else
			moreToSearch = false;
	}
}