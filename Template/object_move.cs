using UnityEngine;
using System.Collections;
public class Sample : MonoBehaviour
{
    private float Speed;
    public bool chk;
    public Vector3 goal;
    RaycastHit hit;
    void Start()
    {
        Speed = 0.1f;
        chk = false;
    }
    void Update()
    {
        if (chk)
        {
            transform.position = Vector3.MoveTowards(transform.position, goal, Speed);

            if (goal == transform.position)
                chk = false;
        }
        if (Input.GetMouseButtonDown(0))
        {

            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            if (Physics.Raycast(ray, out hit, 100000))
            {
                chk = true;
                goal = hit.point;
            }
        }
    }
}
