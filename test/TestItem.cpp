#include <Item.h>
#include <gtest/gtest.h>

/*TEST(TestItem,ConstructorTest){
Item sword(4201);
Item goblin1(3301);
EXPECT_NO_THROW(sword);
EXPECT_THROW(goblin1,invalid_id);
}*/

TEST(TestItem, getiItemValueTest){
Item k(4303);
Item w(4202);
Item p(4101);

 EXPECT_EQ(-3,k.getItemValue());
 EXPECT_EQ(8, w.getItemValue());
 EXPECT_EQ(5, p.getItemValue());
 EXPECT_NE(0, p.getItemValue());
 }
