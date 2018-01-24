namespace CustomContainers {

class UIntSet {
public:
	UIntSet() : root(nullptr) {}
	UIntSet(const UIntSet& iSet) : root(nullptr)
	{ 
		// copy all elements iterating through the whole iSet
	}
	UIntSet(UIntSet&& iSet)
	{ 
		root = iSet.root;
		iSet.root = nullptr;
	}
	UIntSet& operator=(const UIntSet& iSet) 
	{
		if(&iSet == this) return *this;
		
		// clear this set
		// copy all elements iterating through the whole iSet
	}
	UIntSet& operator=(UIntSet&& iSet) 
	{
		if(&iSet == this) return *this;
		
		root = iSet.root;
		iSet.root = nullptr;		
	}

private:
    struct UIntNode;

	UIntNode* root;
};

struct UIntSet::UIntNode {
	UIntNode(unsigned int iValue)
	{
		value = iValue;
		left = nullptr;
		right = nullptr;
	}
	
	~UIntNode() 
	{
		delete left;
		delete right;
	}
	
	unsigned int value;
	UIntNode* left;
	UIntNode* right;
};


}