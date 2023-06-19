#include "global.h"
#include "test_battle.h"

SINGLE_BATTLE_TEST("Guard Spec. sets Mist effect on the battlers side")
{
    GIVEN {
        ASSUME(gItems[ITEM_GUARD_SPEC].battleUsage == EFFECT_ITEM_SET_MIST);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_GUARD_SPEC, partyIndex: 0); }
        TURN { MOVE(opponent, MOVE_GROWL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIST, player);
        MESSAGE("Ally became shrouded in MIST!");
        MESSAGE("Foe Wobbuffet used Growl!");
        MESSAGE("Wobbuffet is protected by MIST!");
    }
}