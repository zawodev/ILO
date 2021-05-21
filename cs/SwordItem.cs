using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SwordItem : Item {

    //PlayerController playerController;
    //CrossHair crossHair;
    HealthMana healthMana;
    //InHandItem handItem;

    [Header("SWORD")]
    public GameObject effect;

    public float damage = 2.3f;
    public float energyCost = 4f;

    public float timeBtwHits = 0.1f;
    float btwHits;

    //bool attackable;

    private void Start() {
        //crossHair = FindObjectOfType<CrossHair>();
        healthMana = FindObjectOfType<HealthMana>();
        //handItem = FindObjectOfType<InHandItem>();
    }
    public override void Use() {
        if (healthMana.CheckMANA(-energyCost)) {
            PlayerController.playerController.anim.SetTrigger("sword");
            //PlayerController.playerController.anim.SetTrigger("sword_attack");
            //PlayerController.playerController.anim.SetTrigger("sword_defense");
            healthMana.GiveMANA(-energyCost);
            //attackable = true;
        }
    }
    /*
    public override void PPMHold() {
        
        healthMana.GiveMANA(-energyCost * Time.deltaTime);
        InHandItem.inHandItem.swordTrailObject.SetActive(true);

        if (!Input.GetKey(KeyCode.LeftShift) && isActive) {
            if (Input.GetMouseButtonDown(0)) {
                if (btwHits <= 0) {
                    Use(); //maybe try to put everything in Use(); in other Script:Item?
                    btwHits = timeBtwHits;
                }
            }
        }
        
    }
    */
    public override void AlwaysUpdate() {
        if (btwHits > 0) btwHits -= Time.deltaTime;
        //else attackable = false;
    }
    public override void ChosenUpdate() {

        if (Input.GetMouseButtonDown(0)) {
            if (PlayerSensors.playerSensors.haveEnemiesInRange /*only if player facing right way by hitbox do it*/) {
                PlayerSensors.playerSensors.GetClosestEnemy();
                //znajdz, nakieruj gracza, animacja ciosu, obrażenia z shaderem białym

            }
            else {
                //uderzenie bez sensu
            }
        }
        if (Input.GetMouseButtonDown(1)) {
            PlayerController.playerController.anim.SetBool("sword_defense", true);
        }

        if (Input.GetMouseButtonUp(1)) {
            PlayerController.playerController.anim.SetBool("sword_defense", false);
        }

        /*
        if (PlayerSensors.playerSensors.haveEnemiesInRange) {
            for (int i = 0; i < PlayerSensors.playerSensors.hitBoxes.Count; i++) {
                Instantiate(effect, PlayerSensors.playerSensors.hitBoxes[i].transform.position, transform.rotation);
                PlayerSensors.playerSensors.hitBoxes[i].DamageEnemy(damage, 50f, PlayerSensors.playerSensors.hitBoxes[i].transform.position - InHandItem.inHandItem.transform.position);
            }
            //attackable = false;
        }
        */
    }
}
