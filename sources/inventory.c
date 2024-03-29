#include "../headers/inventory.h"
#include "../headers/main.h"
#include "../headers/commands.h"
#include "../headers/characters.h"
#include "../headers/items.h"

static void display_inventory(Item** inventory);

void execute_inventory(void)
{
    Item** items = NULL;

    if (!PLAYER->inventory[0])
    {
        add_output("You have no item on you.\n\n");
    }
    else if (!*command.object)
    {
        display_inventory(PLAYER->inventory);
    }
    else
    {
        items = retrieve_items(PLAYER->inventory, command.object);

        if (!items || !items[0])
            add_output("You have no such item on you. Type 'inventory' to see your items.\n\n");
        else if (!items[1])
            add_output("%s\n\n", items[0]->desc_look_item);
        else
            add_output("There is more than one item in your inventory for which this tag works.\n\n");
    }

    free(items);
    return;
}

static void display_inventory(Item** inventory)
{
    int i;
    add_output("--------------------\n");
    add_output("INVENTORY\n\n");
    add_output("\t['Inventory [item]' to see the detailed description of an item.]\n\n");
    for (i = 0; i < NBR_ITEMS; ++i)
    {
        if (!inventory[i])
            break;
        add_output("- [%s]\n\t%s\n", inventory[i]->tags[0], inventory[i]->description);
    }
    add_output("--------------------\n\n");
    return;
}

