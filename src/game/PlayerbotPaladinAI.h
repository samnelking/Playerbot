#ifndef _PlayerbotPaladinAI_H
#define _PlayerbotPaladinAI_H

#include "PlayerbotClassAI.h"

enum
{
    Combat,
    Healing
};

//class Player;

class MANGOS_DLL_SPEC PlayerbotPaladinAI : PlayerbotClassAI
{
    public:
        PlayerbotPaladinAI(Player* const master, Player* const bot, PlayerbotAI* const ai);
        virtual ~PlayerbotPaladinAI();

        // all combat actions go here
        void DoNextCombatManeuver(Unit*);

        // all non combat actions go here, ex buffs, heals, rezzes
        void DoNonCombatActions();

        // buff a specific player, usually a real PC who is not in group
        void BuffPlayer(Player *target);

    private:
		// Heals the target based off its hps, i add this in to see if the healing would be greater then what was give in the pally
        void HealTarget (Unit& target, uint8 hp);

        // RET
        uint32 RETRIBUTION_AURA, SEAL_OF_COMMAND, JUDGEMENT_OF_LIGHT, JUDGEMENT_OF_WISDOM, GREATER_BLESSING_OF_WISDOM, GREATER_BLESSING_OF_MIGHT, BLESSING_OF_WISDOM, BLESSING_OF_MIGHT, HAMMER_OF_JUSTICE, RIGHTEOUS_FURY, CRUSADER_AURA, CRUSADER_STRIKE, AVENGING_WRATH;

        // HOLY
        uint32 FLASH_OF_LIGHT, HOLY_LIGHT, DIVINE_SHIELD, HAMMER_OF_WRATH, CONSECRATION, CONCENTRATION_AURA, SEAL_OF_WISDOM, REDEMPTION;

        //Protection
        uint32 GREATER_BLESSING_OF_KINGS, BLESSING_OF_KINGS, HAND_OF_PROTECTION, SHADOW_RESISTANCE_AURA, DEVOTION_AURA, FIRE_RESISTANCE_AURA, FROST_RESISTANCE_AURA;

        uint32 SpellSequence, CombatCounter, HealCounter;
};

#endif

