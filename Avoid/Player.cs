using UnityEngine;
using System.Collections;

public class Player : MonoBehaviour
{
    public float moveSpeed = 5f;
    public float turnSpeed = 5f;
    // Update is called once per frame
    void Update()
    {
        float h = Input.GetAxis("Horizontal");
        float v = Input.GetAxis("Vertical");
        //Move 
        transform.Translate(h * moveSpeed * Time.deltaTime, 0f, 0f);
        transform.Translate(0f, 0f, v * moveSpeed * Time.deltaTime);
        //Rotation
        transform.Rotate(new Vector3(Input.GetAxis("Mouse Y")*20f, Input.GetAxis("Mouse X")*20f, 0) * Time.deltaTime * turnSpeed);
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("player_"))
        {
            Application.LoadLevel(Application.loadedLevel);
            Debug.Log("" + 123);
        }
        Debug.Log("" + 123);
    }
}
