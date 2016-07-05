using UnityEngine;
using System.Collections;

public class Spawner : MonoBehaviour
{
    public GameObject wallPrefab;
    public float interval;
    public float range = 4.0f;
    static public int score = 0;
    // Use this for initialization
    IEnumerator Start()
    {
        while (true)
        {
            score++;
            transform.position = new Vector3(Random.Range(-range, range), transform.position.y, transform.position.z);
            Instantiate(wallPrefab, transform.position, transform.rotation);
            yield return new WaitForSeconds(interval);
        }
    }

    // Update is called once per frame
    void Update()
    {

    }
}