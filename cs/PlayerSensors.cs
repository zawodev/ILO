using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerSensors : MonoBehaviour {

    public static PlayerSensors playerSensors;

    [HideInInspector]
    public bool haveEnemiesInRange;

    private void Awake() {
        if (playerSensors != null) {
            Destroy(gameObject);
            return;
        }
        else playerSensors = this;
    }

    //[HideInInspector]
    public List<HitBox> hitBoxes;
    public string hitBoxTag = "Body";
    
    private void OnTriggerEnter2D(Collider2D collision) {

        HitBox newHitBox = collision.GetComponent<HitBox>();

        if(newHitBox != null && collision.CompareTag(hitBoxTag)) {
            hitBoxes.Add(newHitBox);
            haveEnemiesInRange = hitBoxes.Count > 0; // if bigger true, if not false
        }
    }
    private void OnTriggerExit2D(Collider2D collision) {

        HitBox oldHitBox = collision.GetComponent<HitBox>();

        if (oldHitBox != null && collision.CompareTag(hitBoxTag)) {
            hitBoxes.Remove(oldHitBox);
            haveEnemiesInRange = hitBoxes.Count > 0;
        }
    }
    public void GetClosestEnemy() {

    }
    public void DisableHitBox(HitBox _hitBox) {
        hitBoxes.Remove(_hitBox);
    }
}
