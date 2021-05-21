using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HitBox : MonoBehaviour{

    [HideInInspector]
    public Enemy enemy;
    [Range(0.1f, 4f)]
    public float multiplier = 1f;

    public bool ragdoll;
    Rigidbody2D rb;

    private void Start() {
        enemy = transform.parent.GetComponentInParent<Enemy>();
        rb = GetComponent<Rigidbody2D>();
    }
    public void DamageEnemy(float _damage, float _enemyRecoil, Vector2 _velocity) {
        if (enemy != null) {
            enemy.TakeDamage(_damage * multiplier, _enemyRecoil * _velocity * 10f);
        }
        if (ragdoll) {
            GaveImpact(_enemyRecoil * _velocity * 10f); // w dwoch miejscach masz podobnie, jeszcze w enemy
        }
    }
    public void GaveImpact(Vector2 power) {
        rb.AddForce(power, ForceMode2D.Force);
    }
}
