#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <string>
#include <vector>

using std::string;
using std::vector;

//This header file is a modified version of the MovieTree.h file given in assignment 7

struct PokeNode{
    int id;
    string name;
    int height;
    int weight;
    string type1;
    string type2;
    string ability;
    string evobase;
    string evomid;
    string evotop;
    PokeNode *parent;
    PokeNode *leftChild;
    PokeNode *rightChild;
    bool isRed;

    PokeNode(){};

    PokeNode(int in_id, std::string in_name, int in_height, int in_weight, string in_type1, string in_type2
             ,string in_ability, string in_evobase, string in_evomid, string in_evotop)
    {
        id = in_id;
        name = in_name;
        height = in_height;
        weight = in_weight;
        type1 = in_type1;
        type2 = in_type2;
        ability = in_ability;
        evobase = in_evobase;
        evomid = in_evomid;
        evotop = in_evotop;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
        isRed = true;

    }

};

class PokeTree
{

    public:
        PokeTree();
        virtual ~PokeTree();
        void printPokeInventory();
        void printPokeTypes();
        void printPokeAbilities();
        int countPokeNodes();
        void searchPokeTree(string name);
        void deletePokeNode(std::string title);
        void addPokeNode(int, string, int, int, string, string, string, string, string, string);
        void findPoke(std::string title);
        void findType(string type);
        void findAbility(string ability);
        bool isValid();
        void whatCountersType();

    protected:

    private:
        void DeleteAll(PokeNode * node);
        void printPokeInventory(PokeNode * node);
        void printPokeTypes(PokeNode * node);
        void printPokeAbilities(PokeNode * node);
        void rbAddFixup(PokeNode * node);
        void leftRotate(PokeNode * x);
        void rbDelete(PokeNode * z);
        void rightRotate(PokeNode * x);
        void rbDeleteFixup(PokeNode * node);
        void rbTransplant(PokeNode * u, PokeNode * v);
        int rbValid(PokeNode *node);
        int countPokeNodes(PokeNode *node);
        void findType(string type, PokeNode *node, vector<PokeNode>*);
        void findAbility(string ability, PokeNode *node, vector<PokeNode>*);
        PokeNode* treeMinimum(PokeNode * node);
        PokeNode* searchPokeTree(PokeNode * node, std::string title);
        PokeNode *root;
        PokeNode *nil;
        int nodeCount;

};

extern vector<PokeNode> typeListing;
extern bool alreadyexists(PokeNode *node);
extern vector<PokeNode> abilityListing;
extern bool alreadyexists2(PokeNode *node);

#endif // BINARYTREE_H
