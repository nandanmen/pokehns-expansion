#ifndef GUARD_CONFIG_DEXNAV_H
#define GUARD_CONFIG_DEXNAV_H

// NOTE: this header is included from constants/global.h *before* IS_HNS is
// defined, so test the raw build define here instead.
#ifdef POKEMON_HNS
#define DEXNAV_ENABLED                TRUE   // Whether or not DexNav is enabled. If TRUE, flags/vars below must all be non-zero
#else
#define DEXNAV_ENABLED                FALSE  // Whether or not DexNav is enabled. If TRUE, flags/vars below must all be non-zero
#endif
#define USE_DEXNAV_SEARCH_LEVELS      FALSE  /* WARNING: POSSIBLY EXCEEDS SAVEBLOCK SPACE! REQUIRES 1 BYTE PER SPECIES */

// Simplified DexNav (HnS): no chains, fixed bonuses, every encounter slot browsable.
#ifdef POKEMON_HNS
#define DEXNAV_USE_CHAINS             FALSE  // If FALSE, the chain never grows, so it gives no level or shiny bonus and isn't shown
#define DEXNAV_PERFECT_IVS            3      // Every DexNav Pokémon gets this many perfect IVs. 0 rolls them from the search level
#define DEXNAV_ALWAYS_EGG_MOVE        TRUE   // Every DexNav Pokémon knows a random egg move, if its evolution line has any
#define DEXNAV_SHOW_UNSEEN            TRUE   // Unseen species show their icon and name and can be searched for
#define DEXNAV_PAUSE_WILD_ENCOUNTERS  TRUE   // No random encounters while sneaking up on a DexNav Pokémon
#define DEXNAV_HELD_ITEM_CHANCE       50     // % chance to hold one of its wild items (rare item 1 in 10). 0 uses the search level
#define DEXNAV_HIDDEN_ABILITY_CHANCE  33     // % chance of its Hidden Ability. 0 uses the search level and needs the species caught before
#else
#define DEXNAV_USE_CHAINS             TRUE
#define DEXNAV_PERFECT_IVS            0
#define DEXNAV_ALWAYS_EGG_MOVE        FALSE
#define DEXNAV_SHOW_UNSEEN            FALSE
#define DEXNAV_PAUSE_WILD_ENCOUNTERS  FALSE
#define DEXNAV_HELD_ITEM_CHANCE       0
#define DEXNAV_HIDDEN_ABILITY_CHANCE  0
#endif

// Flag/var defines
#ifdef POKEMON_HNS
#define DN_FLAG_SEARCHING             FLAG_DEXNAV_SEARCHING
#define DN_FLAG_DEXNAV_GET            FLAG_SYS_POKEDEX_GET // DexNav comes with the Pokédex
#define DN_FLAG_DETECTOR_MODE         FLAG_DEXNAV_DETECTOR_MODE
#define DN_VAR_SPECIES                VAR_DEXNAV_SPECIES
#define DN_VAR_STEP_COUNTER           VAR_DEXNAV_STEP_COUNTER
#else
#define DN_FLAG_SEARCHING             0 // Searching for mon
#define DN_FLAG_DEXNAV_GET            0 // DexNav shows in start menu
#define DN_FLAG_DETECTOR_MODE         0 // Allow player to find hidden mons
#define DN_VAR_SPECIES                0 // Registered DexNav species
#define DN_VAR_STEP_COUNTER           0 // Steps for finding hidden pokemon
#endif

// Search parameters
#define DEXNAV_TIMEOUT                  15  // 15 seconds is the time out. Max of 1092 seconds allowed
#define SNEAKING_PROXIMITY              4   // Tile amount
#define CREEPING_PROXIMITY              2
#define MAX_PROXIMITY                   20

#define DEXNAV_CHAIN_MAX                100 // maximum chain value

// hidden pokemon options - an approximation of values due to lack of available data
#define HIDDEN_MON_STEP_COUNT       100  // Look for hidden pokemon every x steps
#define HIDDEN_MON_SEARCH_RATE      25   // x% chance of finding hidden pokemon every x steps
#define HIDDEN_MON_PROBABILTY       15   // x% chance of finding hidden mon compared to regular encounter data

//// SEARCH PROBABILITIES
// See https://bulbapedia.bulbagarden.net/wiki/DexNav#Benefits
// Chance of encountering egg move at search levels
#define SEARCHLEVEL0_MOVECHANCE         0
#define SEARCHLEVEL5_MOVECHANCE         21
#define SEARCHLEVEL10_MOVECHANCE        46
#define SEARCHLEVEL25_MOVECHANCE        58
#define SEARCHLEVEL50_MOVECHANCE        63
#define SEARCHLEVEL100_MOVECHANCE       83
// Chance of encountering Hidden Abilities at search levels
#define SEARCHLEVEL0_ABILITYCHANCE      0
#define SEARCHLEVEL5_ABILITYCHANCE      0
#define SEARCHLEVEL10_ABILITYCHANCE     5
#define SEARCHLEVEL25_ABILITYCHANCE     15
#define SEARCHLEVEL50_ABILITYCHANCE     20
#define SEARCHLEVEL100_ABILITYCHANCE    23
// Chance of encountering held item
#define SEARCHLEVEL0_ITEM               0
#define SEARCHLEVEL5_ITEM               0
#define SEARCHLEVEL10_ITEM              1
#define SEARCHLEVEL25_ITEM              7
#define SEARCHLEVEL50_ITEM              6
#define SEARCHLEVEL100_ITEM             12
// Chance of encountering one star potential
#define SEARCHLEVEL0_ONESTAR            0
#define SEARCHLEVEL5_ONESTAR            14
#define SEARCHLEVEL10_ONESTAR           17
#define SEARCHLEVEL25_ONESTAR           17
#define SEARCHLEVEL50_ONESTAR           15
#define SEARCHLEVEL100_ONESTAR          8
// Chance of encountering two star potential
#define SEARCHLEVEL0_TWOSTAR            0
#define SEARCHLEVEL5_TWOSTAR            1
#define SEARCHLEVEL10_TWOSTAR           9
#define SEARCHLEVEL25_TWOSTAR           16
#define SEARCHLEVEL50_TWOSTAR           17
#define SEARCHLEVEL100_TWOSTAR          24
// Chance of encountering three star potential
#define SEARCHLEVEL0_THREESTAR          0
#define SEARCHLEVEL5_THREESTAR          0
#define SEARCHLEVEL10_THREESTAR         1
#define SEARCHLEVEL25_THREESTAR         7
#define SEARCHLEVEL50_THREESTAR         6
#define SEARCHLEVEL100_THREESTAR        12

#endif // GUARD_CONFIG_DEXNAV_H
