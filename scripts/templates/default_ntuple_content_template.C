{% extends 'default_ntuple_template.C' %}

{% block GET_PHYS_TEMP_VAR %}
{{CONTENT_GET_PHYS_TEMP_VAR}}
{% endblock %}



{% block PHOTONS %}
{{CONTENT_PHOTONS}}
{% endblock %}



{% block MUONS %}
{{CONTENT_MUONS}}
{% endblock %}



{% block ELECTRONS %}
{{CONTENT_ELECTRONS}}
{% endblock %}



{% block JETS %}
{{CONTENT_JETS}}
{% endblock %}



{% block MET %}
{{CONTENT_MET}}
{% endblock %}



{% block POST_FINISH %}
{{CONTENT_POST_FINISH}}
{% endblock %}