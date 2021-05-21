using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Networking;

public class GameMenager : MonoBehaviour{ //NetworkBehaviour

    public static GameMenager gameMenager;
    public Canvas p1;
    public Canvas p2;
    public Deck d1;
    public Deck d2;

    int x = 0;

    private void Awake() {
        gameMenager = this;
    }
    public int GeneratePlayerIndex() {
        x++;
        return x;
    }

    public bool p1Turn;
    public bool p2Turn;

    private void Start() {
        int r = Random.Range(0, 100);
        if (r % 2 == 0) {
            p1Turn = true;
        }
        else {
            p2Turn = true;
        }
    }
    public void ChangeTurn(Button b) {
        b.interactable = false;

        p1Turn = !p1Turn;
        p2Turn = !p2Turn;

        if (p1Turn) {
            d1.AddMana(1 + d1.bonusMana);
            d1.Dobierz();

            p1.sortingOrder = 1;
            p2.sortingOrder = 0;
        }
        else {
            d2.AddMana(1 + d2.bonusMana);
            d2.Dobierz();

            p1.sortingOrder = 0;
            p2.sortingOrder = 1;
        }
    }
}
