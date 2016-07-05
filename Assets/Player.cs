using UnityEngine;
using System.Collections;
public class Player : MonoBehaviour
{
    public float jumpPower;
    void Start()
    {
        
    }
    void Update()
    {
        if (Input.GetButtonDown("Jump"))
        {
            GetComponent<Rigidbody>().velocity = new Vector3(0, jumpPower, 0);
        }
    }

    void OnCollisionEnter(Collision other)
    {
        Application.LoadLevel(Application.loadedLevel);
    }
}