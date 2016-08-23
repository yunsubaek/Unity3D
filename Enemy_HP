using UnityEngine;
using UnityEngine.UI;

public class Enemy : MonoBehaviour
{
    public float Speed = 5f;
    public float cur_Health = 0f;
    public float max_Health = 100f;
    public RectTransform canvasRectT;
    public GameObject healthBar;
    GameObject bar;

    void Start()
    {
        cur_Health = max_Health;
        bar = Instantiate(healthBar);
        bar.transform.SetParent(canvasRectT.transform, false);
    }

    void Update()
    {
        Vector2 screenPoint = RectTransformUtility.WorldToScreenPoint(Camera.main, transform.position);
        bar.GetComponent<RectTransform>().anchoredPosition = screenPoint - canvasRectT.sizeDelta / 2f;
    }

    void SetHealthBar()
    {
        bar.transform.FindChild("Current_hp").GetComponent<Image>().fillAmount -= 0.1f;
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Bullet"))
        {
            Destroy(other.gameObject);
            if (cur_Health > 0)
            {
                cur_Health -= 10;
                if (cur_Health == 0)
                {
                    Destroy(bar);
                    Destroy(this.gameObject);
                }
                SetHealthBar();
            }
            Debug.Log(name + "총맞음");
            Debug.Log("체력 = " + cur_Health);
        }
    }
}
