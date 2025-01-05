#include "address.ih"

void Address::fillSet(set<pair<string, string>> &postCodeSet)
{
    for (umapItSSV idxData = d_data.begin();
            idxData != d_data.end(); ++idxData) 
    //go through the umap data
        postCodeSet.insert((*idxData).first); //save the keys in a set
}