#include "../headers/characters.h"
#include "../headers/main.h"

/* Declared as extern in ../headers/game.h, included in ../headers/characters.h */
Character list_characters[NBR_CHARACTERS];

static void get_all_tags(char* p_str, const int word_length, Character* object);
static int bool_character_matches_parser(const Character* character, const char* parser);

void populate_list_characters(void)
{
    memset(list_characters, 0, NBR_CHARACTERS * sizeof(Character));

    PLAYER->id = ID_CHARACTER_PLAYER;
    memcpy(PLAYER->tags[0], "player", 6);
    memcpy(PLAYER->tags[1], "self", 4);
    memcpy(PLAYER->tags[2], "me", 2);
    memcpy(PLAYER->tags[3], "myself", 6);
    memcpy(PLAYER->description, "You're a quite handsome fellow.", 31);
    PLAYER->current_location = LOCATION_OUTSIDE;

    CHARACTER_LIBRARIAN->id = ID_CHARACTER_LIBRARIAN;
    memcpy(CHARACTER_LIBRARIAN->tags[0], "mansion librarian", 17);
    memcpy(CHARACTER_LIBRARIAN->tags[1], "librarian", 9);
    memcpy(CHARACTER_LIBRARIAN->description, "The librarian seems friendly.", 29);
    CHARACTER_LIBRARIAN->current_location = LOCATION_OLD_LIBRARY;
    return;
}

void display_character_suggestions(Character** character_collection, const char* command)
{
    int i;
    char* str_tags = NULL;
    int word_length = 0;

    if (!character_collection[0] 
            || (!character_collection[1] && character_collection[0] == PLAYER))
        return;

    word_length = sizeof(character_collection[0]->tags[0]) + 3;
    str_tags = calloc(NBR_TAGS, word_length);

    add_output("\t[Try:]\n");
    for (i = 0; i < NBR_CHARACTERS; ++i)
    {
        if (!character_collection[i])
            break;
        if (character_collection[i] == PLAYER)
            continue;

        get_all_tags(str_tags, word_length, character_collection[i]);
        add_output("\t\t['%s %s'.]\n", command, str_tags);
    }
    add_output("\n");

    free(str_tags);
    return;
}

Character** retrieve_characters(Character** character_collection, const char* parser)
{
    int i, j;
    Character** characters = calloc(NBR_CHARACTERS, sizeof(Character*));
    if (!characters)
        return NULL;

    for (i = 0, j = 0; i < NBR_CHARACTERS; ++i)
    {
        if (!character_collection[i])
            break;

        if (!parser || bool_character_matches_parser(character_collection[i], parser))
            characters[j++] = character_collection[i];
    }

    return characters;
}

static void get_all_tags(char* p_str, const int word_length, Character* object)
{
    int i;

    strncpy(p_str, object->tags[0], word_length);

    for (i = 1; i < NBR_TAGS; ++i)
    {
        if (!object->tags[i][0])
            break;
        strcat(p_str, " / ");
        strncat(p_str, object->tags[i], word_length);
    }
    return;
}

static int bool_character_matches_parser(const Character* character, const char* parser)
{
    int i;
    for (i = 0; i < NBR_TAGS; ++i)
    {
        if (!character->tags[i])
            return 0;

        if (!strcmp(parser, character->tags[i]))
            return 1;
    }
    return 0;
}

