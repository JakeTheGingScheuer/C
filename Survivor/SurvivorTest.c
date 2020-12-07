#include "./Survivor.h"
#include "../unity/unity.h"

void whenCreateNewSurvivorIsCalledAStructIsMadeAppropriatley()
{
    struct Survivor survivor = createNewSurvivor("Jake");
    TEST_ASSERT_EQUAL_STRING("Jake", survivor.name);
    TEST_ASSERT_EQUAL(0, survivor.wounds);
    TEST_ASSERT_EQUAL(3, survivor.actions);
}

void whenWoundSurvivorIsCalledItAddsAWound()
{
    struct Survivor survivor = createNewSurvivor("Jake");
    woundSurvivor(&survivor);
    TEST_ASSERT_EQUAL(1, survivor.wounds);
}

void whenASurvivorGetsTwoWoundsTheyDie()
{
    struct Survivor survivor = createNewSurvivor("Jake");
    woundSurvivor(&survivor);
    woundSurvivor(&survivor);
    TEST_ASSERT_FALSE(isSurvivorAlive(&survivor));
}

void whenASurvivorIsWoundedMoreThanTwiceWoundsAreIgnored()
{
    struct Survivor survivor = createNewSurvivor("Jake");
    woundSurvivor(&survivor);
    woundSurvivor(&survivor);
    woundSurvivor(&survivor);
    TEST_ASSERT_EQUAL(2, survivor.wounds);
}

void cardOneGroup()
{
  whenCreateNewSurvivorIsCalledAStructIsMadeAppropriatley();
  whenWoundSurvivorIsCalledItAddsAWound();
  whenASurvivorGetsTwoWoundsTheyDie();
  whenASurvivorIsWoundedMoreThanTwiceWoundsAreIgnored();
}

void whenPickUpItemIsCalledAddsItToSurvivorsInventory()
{
    struct Survivor survivor = createNewSurvivor("Jake");
    pickUpItem("bat", &survivor);
    TEST_ASSERT_EQUAL_STRING("bat", survivor.inventory[0]);
}

void whenSelectItemFromInventoryIsCalledReturnsItem()
{
    struct Survivor survivor = createNewSurvivor("Jake");
    pickUpItem("bat", &survivor);
    TEST_ASSERT_FALSE(strcmp("bat", selectItemFromInventory("bat", &survivor)));
}

void survivorsCanEquipWhatIsInventory()
{
    struct Survivor survivor = createNewSurvivor("Jake");
    pickUpItem("bat", &survivor);
    equipItem(selectItemFromInventory("bat", &survivor), &survivor);
    TEST_ASSERT_EQUAL_STRING("bat", survivor.inHand[0]);
}

void survivorCanOnlyEquip2Items()
{
  struct Survivor survivor = createNewSurvivor("Jake");
  pickUpItem("bat1", &survivor);
  pickUpItem("bat2", &survivor);
  pickUpItem("bat3", &survivor);
  equipItem(selectItemFromInventory("bat1", &survivor), &survivor);
  equipItem(selectItemFromInventory("bat2", &survivor), &survivor);
  equipItem(selectItemFromInventory("bat3", &survivor), &survivor);
  char* expected[] = { "bat1", "bat2" };
  TEST_ASSERT_EQUAL_STRING_ARRAY(expected, survivor.inHand, 2);

}
void survivorCanOnlyHaveFiveItemsTotal()
{
    struct Survivor survivor = createNewSurvivor("Jake");
    pickUpItem("bat1", &survivor);
    pickUpItem("bat2", &survivor);
    pickUpItem("bat3", &survivor);
    // pickUpItem("bat4", &survivor);
    // pickUpItem("bat5", &survivor);

    TEST_ASSERT_EQUAL_STRING("bat1", survivor.inventory[0]);
    TEST_ASSERT_EQUAL_STRING("bat2", survivor.inventory[1]);
    TEST_ASSERT_EQUAL_STRING("bat3", survivor.inventory[2]);
    // TEST_ASSERT_EQUAL_STRING("bat4", survivor.inventory[3]);
    // TEST_ASSERT_EQUAL_STRING("bat5", survivor.inventory[4]);
}

int main(void)
{
  UNITY_BEGIN();
    RUN_TEST(cardOneGroup);
    RUN_TEST(whenPickUpItemIsCalledAddsItToSurvivorsInventory);
    RUN_TEST(whenSelectItemFromInventoryIsCalledReturnsItem);
    RUN_TEST(survivorsCanEquipWhatIsInventory);
    RUN_TEST(survivorCanOnlyHaveFiveItemsTotal);
  return UNITY_END();
}
