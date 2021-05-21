using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using TMPro;
using UnityEngine.UI;
public class Deck : MonoBehaviour {

    public List<Card> stack = new List<Card>();  //np 30 na start
    public List<Card> hand = new List<Card>();   //5 odejmniac od wyzszej
    //public List<Card> playground = new List<Card>(); //1 odejmniac od wyzszej

    public Transform handParent;
    public Transform rejectParent;
    //public Transform playgroundParent;

    [Space]
    public Button EndTurn;

    [Header("Deck Info")]
    //public GameObject player;
    public int mana;
    public TextMeshProUGUI manaTxt;

    [Space]
    public int maxCards;
    public int cards;

    public int bonusMana;

    void Start() {
        /*if (!isLocalPlayer){
            return;
        }/*/
        CmdSpawnMyDeck();

        foreach (Transform card in rejectParent.transform) {
            stack.Add(card.GetComponent<Card>());
        }
        for (int i = 0; i < cards; i++) {
            Dobierz();
        }
        manaTxt.text = mana.ToString();
    }
    public void Dobierz() {

        EndTurn.interactable = true;

        if (stack.Count > 0 && cards < maxCards) {
            int num = Random.Range(0, stack.Count);
            hand.Add(stack[num]);
            stack[num].transform.SetParent(handParent);
            stack.Remove(stack[num]);
        }
        cards = transform.childCount;
    }
   /*public void NextRound() {
        mana++;
        manaTxt.text = mana.ToString();
        //jakieś czekanie?
        Dobierz();
    }*/
    public void AddMana(int x) {
        mana += x;
        manaTxt.text = mana.ToString();
    }
    public void SubstractMana(int x) {
        mana -= x;
        manaTxt.text = mana.ToString();
    }


    //[Command]
    public void CmdSpawnMyDeck() {
        //tak zeby obaj widzieli z biblioteki co macie w odrzuconych
        //GameObject ob = Instantiate(PlayerUnitPrefab);

        //ob.GetComponent<NetworkIdentity>().AssignClientAuthority(connectionToClient);

        //NetworkServer.SpawnWithClientAuthority(ob, connectionToClient);
    }
}
