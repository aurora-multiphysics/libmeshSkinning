#include"CGALTransferTest.hpp"

class CGALKallaxTransfer : public CGALTransferTest 
{
 protected:
    CGALKallaxTransfer() : CGALTransferTest("kallax.e"){} 

    virtual void OverRide() {BasicTest::TearDown();}
};

TEST_F(CGALKallaxTransfer, checkNums)
{
    ASSERT_EQ(mesh->n_nodes(), refMesh->n_nodes());
    ASSERT_EQ(mesh->n_elem(), refMesh->n_elem());
}

TEST_F(CGALKallaxTransfer, checkNodeSimilarity)
{
    for(int i = 0; i < mesh->max_node_id(); i++)
    {
        ASSERT_EQ(mesh->node_ref(i), refMesh->node_ref(i));
    }

    for(int i = 0; i < mesh->max_elem_id(); i++)
    {
        ASSERT_EQ(mesh->elem_ref(i), refMesh->elem_ref(i));
    }
}


